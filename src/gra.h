#ifndef GRA_H_INCLUDED
#define GRA_H_INCLUDED
int gra(UsePlik &dane)
{
	int x=100,y=100;
	int mx,my,mb;
	BITMAP *teren;
	BITMAP *calosc;
	BITMAP *statek;
	teren=create_bitmap(1000,1000);
	clear_to_color(teren,makecol(250,50,50));
	for(int i=0;i<20;i++)
	for(int j=0;j<20;j++)
	{
		if((i+j)%2)
		{
		rect(teren,i*50,j*50,i*50+49,j*50+49,makecol(50,50,250));
		floodfill(teren,i*50+1,j*50+1,makecol(25,25,200));
		}
		else
		{
			rect(teren,i*50,j*50,i*50+49,j*50+49,makecol(50,250,50));
			floodfill(teren,i*50+1,j*50+1,makecol(25,200,25));
		}


	}
	while (!key[KEY_ESC])
	{
		///////////////////////////////
		//         klawiatura        //
		///////////////////////////////
		if (key[KEY_UP])
		y+=3;
		if (key[KEY_DOWN])
		y-=3;
		if (key[KEY_RIGHT])
		x-=3;
		if (key[KEY_LEFT])
		x+=3;
		///////////////////////////////
		//           mouse           //
		///////////////////////////////
		if(mouse_x<dane[3]/5)
		x+=(dane[3]/5-mouse_x)/15;
		if(mouse_y<dane[4]/5)
		y+=(dane[4]/5-mouse_y)/15;
		if(mouse_x>dane[3]/5*4)
		x-=(mouse_x-dane[3]/5*4)/15;
		if(mouse_y>dane[4]/5*4)
		y-=(mouse_y-dane[4]/5*4)/15;

		if (mouse_b==1)
		{
			;
		}
		///////////////////////////////
		//            draw           //
		///////////////////////////////
		clear_to_color(bufor,0);
		if(x>=dane[3])
		x=x-teren->w;
		if(x<=teren->w*-1)
		x=x+teren->w;
		if(y>0)
		y=0;
		if(y<bufor->h-teren->h)
		y=bufor->h-teren->h;
		draw_sprite(bufor,teren,x,y);
		if(x>0)
		draw_sprite(bufor,teren,x-teren->w,y);
		if(x<dane[3]-teren->w)
		draw_sprite(bufor,teren,x+teren->w,y);
		textprintf(bufor, font, 20, 20, makecol( 200, 200, 200 ), "Myszka x = %d, y = %d, klawisz = %d !,x= %d, y=%d", mouse_x, mouse_y, mouse_b,x,y );
		draw_sprite(screen,bufor,0,0);
		rest(10);
	}
	return 0;
}

#endif // GRA_H_INCLUDED
