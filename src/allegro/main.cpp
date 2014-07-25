#include <head.h>
#include <grafika.h>



void czyscimenuakt();

BITMAP *tekstury;
BITMAP *bufor;
BITMAP *tlo;
FONT *font2;
FONT *font2grob;





void czyscimenu(menu *mene);
void czyscimenu(menu * meneod,menu * menedo,short int przesow);





void czyscimenuakt()
{
    czyscimenu(mena[MenuNum]);
}
void czyscimenu(menu * meneod,menu * menedo,short int przesow_od,short int przesow_do)
{
	draw_sprite(bufor,tlo,0,0);
	(*meneod).rysuj(przesow_od);
	(*menedo).rysuj(przesow_do);
	draw_sprite(screen,bufor,0,0);
}
void czyscimenu(menu * mene)
{
	if((int)MenuNum>(int)PrzesowOd)
	{
		czyscimenu(mena[MenuNum],mena[PrzesowOd],WspolczynnikPrzesowo-menuprzesow,menuprzesow*-1);
	}
	else
	{
		czyscimenu(mena[MenuNum],mena[PrzesowOd],-1*WspolczynnikPrzesowo+menuprzesow,menuprzesow);
	}
    //draw_sprite(bufor,tlo,0,0);
    //(*mene).rysuj();
    //draw_sprite(screen,bufor,0,0);
}


int main()
{
	short int tymdanek[5]={0};
	short int ostmousex=0;
	short int ostmousey=0;
	tymdanek[0]=3;
	tymdanek[1]=3;
	UsePlik dane(tymdanek,5,files+"dane.txt");
	init(dane);
	string lacznik="";
	//BITMAPy
	bufor = create_bitmap(SCREEN_W,SCREEN_H);
	tlo = create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP *okienko_teksturka[3];
	/*lacznik=files+"/test_okienek_rog.bmp";
	okienko_teksturka[0]=load_bmp(lacznik.c_str(),0);
	lacznik=files+"/test_okienek_brzeg.bmp";
	okienko_teksturka[1]=load_bmp(lacznik.c_str(),0);
	lacznik=files+"/test_okienek_srodek.bmp";
	okienko_teksturka[2]=load_bmp(lacznik.c_str(),0);*/

	/*lacznik=files+"/test_przezroczystosci_podstawa.bmp";
	BITMAP *testprzezro=load_bmp(lacznik.c_str(),0);
	lacznik=files+"/test_przezroczystosci_alfa.bmp";
	BITMAP *testprzezro_alfa=load_bmp(lacznik.c_str(),0);*/

	clear_to_color(tlo,makecol(100,110,120));
	clear_to_color(screen,makecol(10,10,10));
	clear_to_color(bufor,makecol(10,10,10));
	//clear_to_color_alfa(tlo,makecol(0,0,0),0.5);
	//draw_sprite_alfa(tlo,testprzezro,testprzezro_alfa,0,0);
	//okienkownik(tlo,okienko_teksturka);
	//FONTy
	//float test=(makecol(250,100,50)/256)%256;
    //textprintf(tlo, font, 20, 20, makecol(255,255,0), "%f", test);

	lacznik=files+"czcionki/czcionka OCR-A BT.pcx";
	font2=load_font(lacznik.c_str(),0,0);
	lacznik=files+"czcionki/czcionka OCR-A BT wieksza groba.pcx";
	font2grob=load_font(lacznik.c_str(),0,0);
    menownik(dane);
	czyscimenuakt();
	SpisMenu OstMenuNum=Glowne;
	short int nacis=-1;
	bool autowspolczynnikprzesowo=true;
	while (true)
    {
    	OstMenuNum=MenuNum;
        if(key[KEY_DOWN])
        {
            if(nacis!=KEY_DOWN&&!key[KEY_UP])
            {
                (*mena[MenuNum]).UstOpcje((*mena[MenuNum]).AktOpcja()+1);
                czyscimenuakt();
                nacis=KEY_DOWN;
            }
        }
        else
        if(key[KEY_UP])
        {
            if(nacis!=KEY_UP)
            {
                (*mena[MenuNum]).UstOpcje((*mena[MenuNum]).AktOpcja()-1);
                czyscimenuakt();
                nacis=KEY_UP;
            }
        }
        else
        if(key[KEY_ENTER]||key[KEY_RIGHT]||mouse_b==1)
        {
            if(nacis!=KEY_ENTER&&nacis!=KEY_RIGHT&&nacis!=200)
            {
                switch(MenuNum)
                {
                    case Glowne:
                    {
                        switch((*mena[(int)Glowne]).AktOpcja())
                        {
                            case 0:
                            {
                                MenuNum=NowaGra;
                                break;
                            }
                            case 1:
                            {
                                MenuNum=WczytajGre;
                                break;
                            }
                            case 2:
                            {
                                //MenuNum=Opcje;
                                break;
                            }
                            case 3:
                            {
                                //MenuNum=Edytor;
                                break;
                            }
                            case 4:
                            {
                            	MenuNum=Koniec;
                            }
                        }
                        break;
                    }
                    case NowaGra:
                    {
                    	switch ((*mena[(int)NowaGra]).AktOpcja())
                    	{
                    		case 0:
                    		{
                    			(*mena[(int)NowaGra]).OpcjaEdycjaUserStringa(0);
                    			break;
                    		}
                    		case 3:
                    		{
                    			MenuNum=NowaGra_Mapy;
                    			break;
                    		}
                    		case 4:
                    		{
                    			gra(dane);
                    			break;
                    		}
                    		case 5:
                    		{
                    			MenuNum=Glowne;
                    			break;
                    		}
                    	}
                    	break;
                    }
                    case NowaGra_Mapy:
                    {
                    	MenuNum=NowaGra;
                    	if (dane.AktWielkoscTablicy((int)SpisMap)==(*mena[(int)NowaGra_Mapy]).AktOpcja())
                    	;//(*mena[(int)NowaGra_Mapy])
                    	else
                    	(*mena[(int)MenuNum]).OpcjaUstString(3,dane.AktWartoscString((int)SpisMap,(*mena[(int)NowaGra_Mapy]).AktOpcja()));
                    	break;
                    }
                }
                nacis=KEY_ENTER;
            }
        }
        else
        if(key[KEY_ESC]||key[KEY_LEFT])
		{
        	if(nacis!=KEY_ESC&&nacis!=KEY_LEFT)
            switch (MenuNum)
            {
                case Glowne:
                {
                    MenuNum=Koniec;
                    break;
                }
                case WczytajGre:
                case Opcje:
                case NowaGra:
                {
                    MenuNum=Glowne;
                    break;
                }
                case NowaGra_Mapy:
                {
                	MenuNum=NowaGra;
                	break;
                }
            }
            nacis=KEY_ESC;
        }
        else
        nacis=-1;
        if(mouse_y!=ostmousey||mouse_x!=ostmousex)
        {
        	short int poprzednia=(*mena[MenuNum]).AktOpcja();
        	(*mena[MenuNum]).UstOpcjeMysz(mouse_x,mouse_y);
        	if((*mena[MenuNum]).AktOpcja()!=poprzednia)
        	czyscimenuakt();
        	ostmousex=mouse_x;
			ostmousey=mouse_y;
        }
        if(OstMenuNum!=MenuNum)
        {
            if(menuprzesow==WspolczynnikPrzesowo||menuprzesow==0||MenuNum!=PrzesowOd)
            {
                menuprzesow=0;
            }
        	else
        	menuprzesow=WspolczynnikPrzesowo-menuprzesow;
        	if(autowspolczynnikprzesowo)
        	WspolczynnikPrzesowo=SCREEN_W;
        	autowspolczynnikprzesowo=true;
        	PrzesowOd=OstMenuNum;
        	speed=0;
        }
        if(PrzesowOd!=MenuNum&&menuprzesow<WspolczynnikPrzesowo&&speed>0)
        {
        	menuprzesow+=przesowV;
        	if(menuprzesow>WspolczynnikPrzesowo)
        	menuprzesow=WspolczynnikPrzesowo;
        	if((int)MenuNum>(int)PrzesowOd)
        	{
        		czyscimenu(mena[MenuNum],mena[PrzesowOd],WspolczynnikPrzesowo-menuprzesow,menuprzesow*-1);
        	}
        	else
        	{
        		czyscimenu(mena[MenuNum],mena[PrzesowOd],-1*WspolczynnikPrzesowo+menuprzesow,menuprzesow);
        	}
        	speed--;
        }
        if(MenuNum==Koniec&&menuprzesow>=WspolczynnikPrzesowo)
        {
        	deinit();
			return 0;
        }
    }
	deinit();
	return 0;
}
END_OF_MAIN()
