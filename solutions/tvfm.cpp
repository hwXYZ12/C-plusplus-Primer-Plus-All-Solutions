// tvfm.cpp - ch15e1
#include "tvfm.h";
#include <iostream>;

namespace TELEVISION
{
	// normally would have an upper limit on the volume
	// but we don't need it for the exercise
	bool Tv::volup()
	{
		volume++;
		return true;
	}

	bool Tv::voldown()
	{
		if(volume >=0)
		{
			volume--;
			return true;
		}
		return false;
	}

	void Tv::chanup()
	{
		if (channel < maxchannel)
			channel++;
	}

	void Tv::chandown()
	{
		if(channel >= 0)
			channel--;
	}

	void Tv::toggleModus(Remote & r)
	{
		if (state == On)
		{
			r.modusOperandi = (r.modusOperandi == Remote::Normal) ? Remote::Interactive: Remote::Normal;
		}

	}

	void Tv::settings() const
	{
		using std::cout;
		using std::endl;
		cout << "State: " << state << endl
			 << "Volume: " << volume << endl
			 << "MaxChannel: " << maxchannel << endl
			 << "Channel: " << channel << endl
			 << "Mode: " << mode << endl
			 << "Input: " << input << endl;
	}

	void Remote::showModusOperandi()
	{
		std::cout << "Remote Mode: " << modusOperandi << std::endl;
	}

}
