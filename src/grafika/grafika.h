#ifndef GRAFIKA_H_INCLUDED
#define GRAFIKA_H_INCLUDED
int min (int a,float b)
{
	if(a<b)
	return a;
	else
	return b;
}
void clear_to_color_alfa(BITMAP *cel,int color,float alpha)
{
    float red=color/256/256;
    float green=(color/256)%256;
    float blue=color%256;
    for(unsigned int j=0;j<cel->h;j++)
	for(unsigned int i=0;i<cel->w*4;i++)
	{
	    switch(i%4)
	    {
	        case 0:
            cel->line[j][i]=(unsigned char)max(0,min(255,((float)cel->line[j][i]*(1.0f-alpha)+blue*alpha)));
	        break;
	        case 1:
	        cel->line[j][i]=(unsigned char)max(0,min(255,((float)cel->line[j][i]*(1.0f-alpha)+green*alpha)));
	        break;
	        case 2:
	        cel->line[j][i]=(unsigned char)max(0,min(255,((float)cel->line[j][i]*(1.0f-alpha)+red*alpha)));
	        break;
	    }
	}
}
void draw_sprite_alfa(BITMAP *cel,BITMAP *nakladka, BITMAP *nakladka_alfa,int x,int y)
{
	float alpha=1;
	BITMAP *tmp=create_bitmap(nakladka->w,nakladka->h);
	draw_sprite(tmp,cel,x,y);
	for(unsigned int j=0;j<nakladka->h;j++)
	for(unsigned int i=0;i<nakladka->w*4;i++)
	{
		alpha=(float)getr(getpixel(nakladka_alfa,i/4,j))/255.0;
		//putpixel(cel,j+x,i+y,max(0,min(255*255*255,((float)(getpixel(cel,j+x,i+y)*(1.0f-alpha)+(float)getpixel(nakladka,j,i)*alpha)))));
		tmp->line[j][i]=(unsigned char)max(0,min(255,(float)tmp->line[j][i]*(1.0f-alpha)+(float)nakladka->line[j][i]*alpha));
	}
	draw_sprite(cel,tmp,x,y);
	destroy_bitmap(tmp);
}
void okienkownik(BITMAP *cel,BITMAP *teksturka[3])
{
	draw_sprite(cel,teksturka[0],0,0);

	rotate_sprite(cel,teksturka[0],cel->w-teksturka[0]->w,0,itofix(64));
	rotate_sprite(cel,teksturka[0],cel->w-teksturka[0]->w,cel->h-teksturka[0]->h,itofix(128));
	rotate_sprite(cel,teksturka[0],0,cel->h-teksturka[0]->h,itofix(192));

	for(int i=teksturka[0]->h;i<=cel->h-teksturka[0]->h-teksturka[1]->h;i+=teksturka[1]->h)
	draw_sprite(cel,teksturka[1],0,i);
	for(int i=teksturka[0]->w;i<=cel->w-teksturka[0]->w-teksturka[1]->h;i+=teksturka[1]->h)
	rotate_sprite(cel,teksturka[1],i+teksturka[1]->h/2.0-teksturka[1]->w/2.0,0-teksturka[1]->h/2.0+teksturka[1]->w/2.0,itofix(64));
	for(int i=teksturka[0]->h;i<=cel->h-teksturka[0]->h-teksturka[1]->h;i+=teksturka[1]->h)
	rotate_sprite(cel,teksturka[1],cel->w-teksturka[1]->w,i,itofix(128));
	for(int i=teksturka[0]->w;i<=cel->w-teksturka[0]->w-teksturka[1]->h;i+=teksturka[1]->h)
	rotate_sprite(cel,teksturka[1],i+teksturka[1]->h/2.0-teksturka[1]->w/2.0,cel->h-teksturka[1]->w-teksturka[1]->h/2.0+teksturka[1]->w/2.0,itofix(192));
	for(int i=teksturka[0]->w;i<=cel->w-teksturka[0]->w-teksturka[2]->w;i+=teksturka[2]->w)
	for(int j=teksturka[0]->h;j<=cel->h-teksturka[0]->h-teksturka[2]->h;j+=teksturka[2]->h)
	draw_sprite(cel,teksturka[2],i,j);
}
#endif // GRAFIKA_H_INCLUDED
