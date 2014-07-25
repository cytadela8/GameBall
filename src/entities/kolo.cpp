#include "kolo.h"

#define PI 3.14159265
kolo::kolo()
{
	ingol=false;
	bramka=false;
	stat=false;
}
kolo::kolo(sf::Sprite spritekx,double vxx,double vyx,int rx,int mx,double maxvd,double WspolTarD)
{
	bramka=false;
	stat=false;
	Load(spritekx,vxx,vyx,rx,mx,WspolTarD);
}
kolo::~kolo()
{
	//dtor
}

bool kolo::Load(sf::Sprite spritekx,double vxx,double vyx,int rx,int mx,double WspolTarD)
{
	WspolTar=WspolTarD;
	spritek=spritekx;
	vx=vyx;
	vy=vxx;
	r=rx;
	m=mx;
	spritek.SetCenter(spritek.GetSubRect().GetWidth()/2,spritek.GetSubRect().GetHeight()/2);
	return 0;
}
bool kolo::ZderzenieAnaliz(double ftime,kolo * obiekt2,int & bg,int & bd,int & bl,int & bp,int & bram)
{
	double dan=((this->GetX()-obiekt2->GetX())*(this->GetX()-obiekt2->GetX())+(this->GetY()-obiekt2->GetY())*(this->GetY()-obiekt2->GetY()));
	if (sqrt(dan)>GetR()+obiekt2->GetR())
		return false;
	double ptime=0;
	double ktime=ftime;
	double akttime=ftime;
	while (ktime-ptime>0.001&&ptime>0)
	{
		this->Animate((ptime+(ktime-ptime)/2)-akttime,bg,bd,bl,bp,bram);
		obiekt2->Animate((ptime+(ktime-ptime)/2)-akttime,bg,bd,bl,bp,bram);
		akttime=(ptime+(ktime-ptime)/2);
		dan=((this->GetX()-obiekt2->GetX())*(this->GetX()-obiekt2->GetX())+(this->GetY()-obiekt2->GetY())*(this->GetY()-obiekt2->GetY()));
		if (sqrt(dan)>GetR()+obiekt2->GetR())
			ptime=akttime;
		else
			ktime=akttime;
	}
	if (akttime!=ptime)
	{
		this->Animate(ptime-akttime,bg,bd,bl,bp,bram);
		obiekt2->Animate(ptime-akttime,bg,bd,bl,bp,bram);
	}

	PrzeliczZderzenie(obiekt2);
	this->Animate(ftime-akttime,bg,bd,bl,bp,bram);
	obiekt2->Animate(ftime-akttime,bg,bd,bl,bp,bram);
	ZderzenieAnaliz(ftime-akttime,obiekt2,bg,bd,bl,bp,bram);
	return true;
}
double kolo::TZderzenieScian()
{
	const double INF=100000;
	if (!stat)
	{

	}
	return INF;
}
long double kolo::TZderzenia(kolo * o2)
{
	const long double sblad=0.000001;
	const long double INF=100000;
	//double V1=sqrt(this->GetVX()*this->GetVX()+this->GetVY()*this->GetVY());
	//double V2=sqrt(o2->GetVX()*o2->GetVX()+o2->GetVY()*o2->GetVY());
	//double k1=atan(this->GetY()/this->GetX());
	//double k2=atan(o2->GetY()/o2->GetX());
	long double a=(o2->GetVX()-this->GetVX())*(o2->GetVX()-this->GetVX())+(o2->GetVY()-this->GetVY())*(o2->GetVY()-this->GetVY());//double a=V1*V1+V2*V2-2*V1*V2*cos(k1-k2);
	long double b=2*((o2->GetX()-this->GetX())*(o2->GetVX()-this->GetVX())+(o2->GetY()-this->GetY())*(o2->GetVY()-this->GetVY()));//double b=-2*((this->GetX()+o2->GetX())*(V1*cos(k1)+V2*cos(k2))+(this->GetY()+o2->GetY())*(V1*sin(k1)+V2*sin(k2)));
	long double c=(this->GetX()-o2->GetX())*(this->GetX()-o2->GetX())+(this->GetY()-o2->GetY())*(this->GetY()-o2->GetY())-(this->GetR()+o2->GetR())*(this->GetR()+o2->GetR());
	long double delta=b*b-4*a*c;
	if (delta>=0)
	{
		//cout << "DELTA > 0 ";
		long double t1=(-b-sqrt(delta))/(2*a);
		long double t2=(-b+sqrt(delta))/(2*a);
		//cout << t1 << " " <<  t2 << endl;
		if ((t1)>=0||t2>=0)
		{
			if ((t1)<t2)
				if((t1)>=0)
				{
					if (((this->GetX()+this->GetVX()*(t1+sblad))-(o2->GetX()+o2->GetVX()*(t1+sblad)))*((this->GetX()+this->GetVX()*(t1+sblad))-(o2->GetX()+o2->GetVX()*(t1+sblad)))+((this->GetY()+this->GetVY()*(t1+sblad))-(o2->GetY()+o2->GetVY()*(t1+sblad)))*((this->GetY()+this->GetVY()*(t1+sblad))-(o2->GetY()+o2->GetVY()*(t1+sblad)))-(this->GetR()+o2->GetR())*(this->GetR()+o2->GetR())<=0)
						return t1;
				}
				else
				{
					if (((this->GetX()+this->GetVX()*(t2+sblad))-(o2->GetX()+o2->GetVX()*(t2+sblad)))*((this->GetX()+this->GetVX()*(t2+sblad))-(o2->GetX()+o2->GetVX()*(t2+sblad)))+((this->GetY()+this->GetVY()*(t2+sblad))-(o2->GetY()+o2->GetVY()*(t2+sblad)))*((this->GetY()+this->GetVY()*(t2+sblad))-(o2->GetY()+o2->GetVY()*(t2+sblad)))-(this->GetR()+o2->GetR())*(this->GetR()+o2->GetR())<=0)
						return t2;
				}
			else if(t2>=0)
			{
				if (((this->GetX()+this->GetVX()*(t2+sblad))-(o2->GetX()+o2->GetVX()*(t2+sblad)))*((this->GetX()+this->GetVX()*(t2+sblad))-(o2->GetX()+o2->GetVX()*(t2+sblad)))+((this->GetY()+this->GetVY()*(t2+sblad))-(o2->GetY()+o2->GetVY()*(t2+sblad)))*((this->GetY()+this->GetVY()*(t2+sblad))-(o2->GetY()+o2->GetVY()*(t2+sblad)))-(this->GetR()+o2->GetR())*(this->GetR()+o2->GetR())<=0)
					return t2;
			}
			else
			{
				if (((this->GetX()+this->GetVX()*(t1+sblad))-(o2->GetX()+o2->GetVX()*(t1+sblad)))*((this->GetX()+this->GetVX()*(t1+sblad))-(o2->GetX()+o2->GetVX()*(t1+sblad)))+((this->GetY()+this->GetVY()*(t1+sblad))-(o2->GetY()+o2->GetVY()*(t1+sblad)))*((this->GetY()+this->GetVY()*(t1+sblad))-(o2->GetY()+o2->GetVY()*(t1+sblad)))-(this->GetR()+o2->GetR())*(this->GetR()+o2->GetR())<=0)
					return t1;
			}

		}
	}
	return INF;
}
double kolo::PrzeliczZderzenie(kolo * obiekt2,double addpow)
{
	cout << "1: " << this->GetVX() << " " << this->GetVY() << " 2: " << obiekt2->GetVX() << " " << obiekt2->GetVY() << endl;
	double A=atan ((obiekt2->GetY()-this->GetY())/(obiekt2->GetX()-this->GetX()));
	double v1n;
	double v2n;
	double v1moc;
	double v2moc;
	if (obiekt2->GetX()>this->GetX())
	{
		if (addpow>0)
		{
			v1n=-addpow;
			v2n=-addpow;
			v1moc=cos(A)*this->GetVX()+sin(A)*this->GetVY()-addpow;
			v2moc=cos(A)*obiekt2->GetVX()+sin(A)*obiekt2->GetVY()-addpow;
		}
		else
		{
			v1n=cos(A)*this->GetVX()+sin(A)*this->GetVY()-addpow;
			v2n=cos(A)*obiekt2->GetVX()+sin(A)*obiekt2->GetVY()-addpow;
			v1moc=v1n;
			v2moc=v2n;
		}

	}
	else
	{
		if (addpow>0)
		{
			v1n=addpow;
			v2n=addpow;
			v1moc=cos(A)*this->GetVX()+sin(A)*this->GetVY()+addpow;
			v2moc=cos(A)*obiekt2->GetVX()+sin(A)*obiekt2->GetVY()+addpow;
		}
		else
		{
			v1n=cos(A)*this->GetVX()+sin(A)*this->GetVY()+addpow;
			v2n=cos(A)*obiekt2->GetVX()+sin(A)*obiekt2->GetVY()+addpow;
			v1moc=v1n;
			v2moc=v2n;
		}
	}
	double v1s=sin(A)*this->GetVX()-cos(A)*this->GetVY();
	double v2s=sin(A)*obiekt2->GetVX()-cos(A)*obiekt2->GetVY();
	cout << "1: " << v1n << " " << v1s << " 2: " << v2n << " " << v2s << endl;
	double v=(this->GetM()*v1n+obiekt2->GetM()*v2n)/(this->GetM()+obiekt2->GetM());
	double v1pn=2*v-v1n;
	double v2pn=2*v-v2n;
	if (stat||obiekt2->GetStat())
	{
		v1pn=v1n*-1;
		v2pn=v2n*-1;
	}
	cout << "1: " << v1pn << " 2: " << v2pn << endl;
	this->SetVX(cos(A)*v1pn+sin(A)*v1s);
	this->SetVY(sin(A)*v1pn-cos(A)*v1s);
	cout << this->GetVX() << " " << this->GetVY() << endl;
	obiekt2->SetVX(cos(A)*v2pn+sin(A)*v2s);
	obiekt2->SetVY(sin(A)*v2pn-cos(A)*v2s);
	cout << obiekt2->GetVX() << " " << obiekt2->GetVY() << endl;
	if (addpow>0)
	{
		if (v1n>v2n)
		return v1moc-v2moc+addpow;
		else
		return v2moc-v1moc+addpow;
	}
	else
	{
		if (v1n>v2n)
		return v1moc-v2moc;
		else
		return v2moc-v1moc;
	}

}
void kolo::Draw(sf::RenderWindow &App)
{
	App.Draw(spritek);
}
void kolo::Animate(double ftime,int & bg,int & bd,int & bl,int & bp,int & bram)
{
	if (!stat)
	{
		if (!bramka&&((vx>1||vx<-1)||(vy>1||vy<-1)))
		{
			if ((vx>1||vx<-1)&&(vy>1||vy<-1))
			{
				spritek.SetRotation(atan(vx/vy)*180/PI);
				if (vy<0)
				spritek.Rotate(180);
			}

			else
			{
				if ((vy>1||vy<-1))
				{
					if (vy>0)
					spritek.SetRotation(0);
					else
					spritek.SetRotation(180);
				}
				else
				{
					if (vx>0)
					spritek.SetRotation(90);
					else
					spritek.SetRotation(360-90);
				}
			}
			spritek.Rotate(90);
			if (spritek.GetRotation()>90&&spritek.GetRotation()<360-90)
				spritek.FlipY(true);
			else
				spritek.FlipY(false);
		}
		spritek.Move(vx*ftime,vy*ftime);
		if (!ingol)
		{
		if (spritek.GetPosition().x+r>bp&&(spritek.GetPosition().y+r<bg+((bd-bg)-bram)/2||spritek.GetPosition().y+r>bd-((bd-bg)-bram)/2||!bramka))
		{
			spritek.SetPosition((spritek.GetPosition().x+r-bp)*-1-r+bp,spritek.GetPosition().y);
			vx*=-1;
		}
		if (spritek.GetPosition().x-r<bl&&(spritek.GetPosition().y+r<bg+((bd-bg)-bram)/2||spritek.GetPosition().y+r>bd-((bd-bg)-bram)/2||!bramka))
		{
			spritek.SetPosition((spritek.GetPosition().x-r-bl)*-1+r+bl,spritek.GetPosition().y);
			vx*=-1;
		}
		if (spritek.GetPosition().y+r>bd)
		{
			spritek.SetPosition(spritek.GetPosition().x,(spritek.GetPosition().y+r-bd)*-1-r+bd);
			vy*=-1;
		}
		if (spritek.GetPosition().y-r<bg)
		{
			spritek.SetPosition(spritek.GetPosition().x,(spritek.GetPosition().y-r-bg)*-1+bg+r);
			vy*=-1;
		}
		}

	}
		if (spritek.GetPosition().x<bl||spritek.GetPosition().x>bp||spritek.GetPosition().y<bg||spritek.GetPosition().y>bd)
		ingol=true;
		else
		ingol=false;
}
void kolo::ZasTarcie(double ftime,double prog)
{
	if (!stat)
	{
		if (vx*vx+vy*vy>0)
		{
			double WspolTarDoc=WspolTar;
			double v=sqrt(vx*vx+vy*vy);
			if (v<prog)
			{
				WspolTarDoc=(v/prog)*WspolTar;
			}
			if (v>WspolTarDoc*ftime)
			{
				vx=vx*(v-WspolTarDoc*ftime)/v;
				vy=vy*(v-WspolTarDoc*ftime)/v;
			}
			else
			{
				vx=0;
				vy=0;
			}

		}
	}

}
double kolo::GetX()
{
	return spritek.GetPosition().x;
}
double kolo::GetY()
{
	return spritek.GetPosition().y;
}
void kolo::SetX(double xe)
{
	spritek.SetPosition(xe,GetY());
}
void kolo::SetY(double ye)
{
	spritek.SetPosition(GetX(),ye);
}
void kolo::SetPos(double xe, double ye)
{
	spritek.SetPosition(xe,ye);
}
void kolo::SetRotation(int rot)
{
	spritek.SetRotation(rot);
	if (spritek.GetRotation()>90&&spritek.GetRotation()<360-90)
		spritek.FlipY(true);
	else
		spritek.FlipY(false);
}
double kolo::GetVX()
{
	return vx;
}
double kolo::GetVY()
{
	return vy;
}
void kolo::SetVX(double danvx)
{
	if (!stat)
		vx=danvx;
}
void kolo::SetVY(double danvy)
{
	if (!stat)
		vy=danvy;
}
void kolo::SetV(double danvx,double danvy)
{
	if (!stat)
		vx=danvx;
	if (!stat)
		vy=danvy;
}
int kolo::GetR()
{
	return r;
}
int kolo::GetM()
{
	return m;
}
void kolo::setbram(bool bramkad)
{
	bramka=bramkad;
}
bool kolo::GetStat()
{
	return stat;
}
void kolo::setstat(bool statek)
{
	stat=statek;
}
double kolo::todod(double dan)
{
	if (dan<0)
		return dan*-1;
	else
		return dan;
}
void kolo::PopV(double maxv)
{
	if (vx*vx+vy*vy>0&&sqrt(vx*vx+vy*vy)>maxv)
	{
		double v=sqrt(vx*vx+vy*vy);
		vx=vx*maxv/v;
		vy=vy*maxv/v;
	}
}
void kolo::SetTarcie(double tarcied)
{
	WspolTar=tarcied;
}
/*void kolo::PopVc()
{
    if (vx*vx+vy*vy>0)
    {
        //cout << sqrt(vx*vx+vy*vy) << "\n";
        if (sqrt(vx*vx+vy*vy)>maxv)
    {
        //cout << " SPOWALNIANIE... ";
        double zmniej;
        if (vx>vy)
        zmniej=(sqrt(maxv*maxv-vx*vx-vy*vy+(todod(vx)-todod(vy))*(todod(vx)-todod(vy))/2)+sqrt(2)/2*(todod(vx)-todod(vy)))/sqrt(2);
        else
        zmniej=(sqrt(maxv*maxv-vx*vx-vy*vy+(todod(vy)-todod(vx))*(todod(vy)-todod(vx))/2)+sqrt(2)/2*(todod(vy)-todod(vx)))/sqrt(2);
        cout << " zmniej= " << zmniej << " vx= " << vx << " vy= " << vy << " maxv= " << maxv;
        if (vx<0)
        {
            vx+=zmniej;
            if (vx>0)
                vx=0;
        }
        else
        {
            vx-=zmniej;
            if (vx<0)
                vx=0;
        }
        if (vy<0)
        {
            vy+=zmniej;
            if (vy>0)
                vy=0;
        }
        else
        {
            vy-=zmniej;
            if (vy<0)
                vy=0;
        }
    }
    }

}
void kolo::PopVx()
{
	if (vx*vx+vy*vy>0&&sqrt(vx*vx+vy*vy)>maxv)
	{
		double zmniej=sqrt(maxv*maxv-vy*vy)+vx;
		if(vx<0)
		{
			vx+=zmniej;
			if (vx>0)
				vx=0;
		}
		else
		{
			vx-=zmniej;
			if (vx<0)
				vx=0;
		}
	}
}
void kolo::PopVy()
{
	if (vx*vx+vy*vy>0&&sqrt(vx*vx+vy*vy)>maxv)
	{
		double zmniej=sqrt(maxv*maxv-vx*vx)+vy;
		if(vy<0)
		{
			vy+=zmniej;
			if (vy>0)
				vy=0;
		}
		else
		{
			vy-=zmniej;
			if (vy<0)
				vy=0;
		}
	}
}*/
