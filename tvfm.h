// tvfm.h - Tv and Remote classes using a friend member
#ifndef TVFM_H_
#define TVFM_H_

namespace TELEVISION
{

	class Tv;						// forward declaration

	class Remote
	{
		friend class Tv;

	public:
		enum State{Off, On};
		enum Modus{Normal, Interactive};
		enum {MinVal, MaxVal = 20};
		enum {Antenna, Cable};
		enum {TV, DVD};
	private:
		int mode;
		int modusOperandi;
	public:
		Remote(int m = TV, int modus = Normal)
			   : mode(m), modusOperandi(modus)
		{}
		bool volup(Tv & t);
		bool voldown(Tv & t);
		void onoff(Tv & t);
		void chanup(Tv & t);
		void chandown(Tv & t);
		void set_mode(Tv & t);
		void set_input(Tv & t);
		void set_chan(Tv & t, int c);
		void showModusOperandi();
	};

	class Tv
	{
		friend class Remote;

	public:
		friend void Remote::set_chan(Tv & t, int c);
		enum State{Off, On};
		enum {MinVal, MaxVal = 20};
		enum {Antenna, Cable};
		enum {TV, DVD};

		Tv(int s = Off, int mc = 125)
		   : state(s), volume(5), maxchannel(mc),
			 channel(2), mode(Cable), input(TV)
		{}
		void onoff()							{ state = (state == On) ? Off : On; }
		bool ison() const						{ return state == On; }
		bool volup();
		bool voldown();
		void chanup();
		void chandown();
		void set_mode()							{ mode = (mode == Antenna) ? Cable : Antenna; }
		void set_input()						{ input = (input == TV) ? DVD : TV; }
		void toggleModus(Remote & r);
		void settings() const;


	private:
		int state;
		int volume;
		int maxchannel;
		int channel;
		int mode;
		int input;
	};

	// Remote methods as inline functions
	inline bool Remote::volup(Tv & t)				{ return t.volup(); }
	inline bool Remote::voldown(Tv & t)				{ return t.voldown(); }
	inline void Remote::onoff(Tv & t)				{ return t.onoff(); }
	inline void Remote::chanup(Tv & t)				{ return t.chanup(); }
	inline void Remote::chandown(Tv & t)			{ return t.chandown(); }
	inline void Remote::set_mode(Tv & t)			{ return t.set_mode(); }
	inline void Remote::set_input(Tv & t)			{ return t.set_input(); }
	inline void Remote::set_chan(Tv & t, int c)		{ t.channel = c; }

}



#endif