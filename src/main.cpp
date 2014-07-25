
#include <main.h>
#include <iostream>
int init(sf::RenderWindow &App,int s=-1,int w=-1,bool r=0)
{
    if (s==-1 || w==-1)
    {
        if (dane[BFullScreen])
        {
            App.Create(sf::VideoMode(dane[ISScreen], dane[IWScreen]), "GameBall", sf::Style::Fullscreen);
        }
        else
        {
            App.Create(sf::VideoMode(dane[ISScreen], dane[IWScreen]), "GameBall");
        }
    }
    else
    {
        if (r)
            App.Create(sf::VideoMode(s,w), "Gameball", sf::Style::Fullscreen);
        else
            App.Create(sf::VideoMode(s,w), "Gameball");
    }
}

int main()
{
    cout << "test";
    sf::RenderWindow App;
    string tmp=files+"dane.txt";
    dane.INIT(PDtab,tmp);
    dane.Zapis();
    init(App);
    sf::Font gamefont;
    gamefont.LoadFromFile(files+"czcionki/aardvarkbold.TTF",100);
    screen_p * wskazscreen [IlEkr+1];
    screen_p * tloscreen;
    wskazscreen[0]=0;
    wskazscreen[1]=new intro_screen(App);
    wskazscreen[2]=new menu_screen(dane,App);
    wskazscreen[3]=new gra_screen(App,gamefont);
    wskazscreen[4]=new zamykanie_screen;
    wskazscreen[5]=new FPS;
    wskazscreen[6]=new Gol_screen(App,gamefont);
    wskazscreen[7]=new opcja_tekst();
    wskazscreen[8]=new opcja_klaw(250,20,20,App);
    wskazscreen[9]=new opcja_czas();
    tloscreen=new tlo_screen;
    screen_c SC;
    SC.Load(IlEkr,wskazscreen,tloscreen);
    #ifdef Release
    SC.Acctive(1);
    #else
    SC.Acctive(2);
    SC.Acctive(5);
    #endif
    wskazscreen[3]->Load();
    //App.SetFramerateLimit(60);
    //SC.Acctive(2);
    //menu
    //gra
    //sf::String test("Testowy tekst");
    int popret,ret;
    while (App.IsOpened())
    {
        //App.Draw(test);
        //App.Display();
        popret=ret;
        ret=SC.Render(App);
        if (popret!=ret)
        cout << "NOWY ZWROT: " << ret << "\n";
        if (!ret)
            App.Close();
    }
    cout << "EXITUJE!";
    return EXIT_SUCCESS;
}
