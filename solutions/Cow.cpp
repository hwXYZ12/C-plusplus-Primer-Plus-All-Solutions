// Cow.cpp - ch12e1
#include "Cow.h";
#include <iostream>;

namespace COW
{
	// default constructor
	Cow::Cow()
	{

		// sets default hobby
		m_hobby = nullptr;

		// copies default name to the name array
		// note that we must account for the null character
		for(int i=0; i <= NAME_LENGTH; i++)
		{
			m_name[i] = DEFAULT_NAME[i];
			if ('\0' == DEFAULT_NAME[i])
				break;
		}
		// ensures that the C-style string is null terminated
		m_name[NAME_LENGTH] = '\0';

		// set default weight
		m_weight = DEFAULT_WEIGHT;
	}

	// constructor
	Cow::Cow(const char * name, const char * hobby, double weight)
	{
		// copies the character string
		// pointed to by name into the m_name array
		// note that we must account for the null character
		for(int i=0; i <= NAME_LENGTH; i++)
		{
			m_name[i] = name[i];
			if ('\0' == name[i])
				break;
		}
		// ensures that the C-style string is null terminated
		m_name[NAME_LENGTH] = '\0';


		// copy hobby to m_hobby
		long len = strlen(hobby);
		if (nullptr == hobby)
		{
			m_hobby = nullptr;
		}
		else if (len <= 0)
		{
			m_hobby = new char[1];
			m_hobby[0] = '\0';
		}
		else
		{
			// allocates space for a new C-style string
			// need len + 1 for the null character!
			m_hobby = new char[len+1];

			// copies the character string
			// pointed to by hobby into the new array pointed to by m_hobby
			for(int i=0; i <= len; i++)
			{
				m_hobby[i] = hobby[i];
				if ('\0' == hobby[i])
					break;
			}
			// ensures that the C-style string is null terminated
			m_hobby[len] = '\0';
		}

		// records the given weight
		m_weight = weight;
		
	}

	// copy constructor
	Cow::Cow(const Cow & c)
	{
		// copies the character string
		// m_name of c into the character string
		// m_name of this object
		// note we must account for the null character
		for(int i=0; i <= NAME_LENGTH; i++)
		{
			m_name[i] = c.m_name[i];
			if ('\0' == c.m_name[i])
				break;
		}
		// ensures that the C-style string is null terminated
		m_name[NAME_LENGTH] = '\0';

		// copies the character string m_hobby of c
		// into the character string m_hobby of this
		// object. Note that we're dealing with
		// pointers so we may need to allocate space
		// or skip this procedure altogether.
		// Note also that we must account for the null
		// character.

		// strlen() can't handle a nullptr so
		// we must check that first
		if (nullptr == c.m_hobby)
			m_hobby = nullptr;
		else
		{
			// now get the string length
			// and copy c.m_hobby to m_hobby
			long len = strlen(c.m_hobby); 
			if (len <= 0)
			{
				m_hobby = new char[1];
				m_hobby[0] = '\0';		
			}
			else
			{
				// allocate space for the new character array
				// +1 for the null character
				m_hobby = new char[len+1];
				// copy from c.m_hobby into m_hobby
				for(int i=0; i <= len; i++)
				{
					m_hobby[i] = c.m_hobby[i];
					if ('\0' == c.m_hobby[i])
						break;
				}
				// ensures that the C-style string is null terminated
				m_hobby[len] = '\0';
			}
		}

		// overwrites weight
		m_weight = c.m_weight;
	}

	// destructor
	Cow::~Cow()
	{
		delete [] m_hobby;
	}

	// assignment operator overload
	Cow & Cow::operator=(const Cow & c)
	{
		// copies the character string
		// name of c into the character string
		// name of this object
		for(int i=0; i <= NAME_LENGTH; i++)
		{
			m_name[i] = c.m_name[i];
			if ('\0' == c.m_name[i])
				break;
		}
		// ensures that the C-style string is null terminated
		m_name[NAME_LENGTH] = '\0';

		// copies the character string hobby of c
		// into the character string hobby of this
		// object. Note that we're dealing with
		// pointers so we may need to allocate space
		// or skip this procedure altogether.
		// We also need to consider the case that 
		// m_hobby points to space that ought to be
		// freed so we free it immediately.
		// Note that we must also take into
		// account the null character.
		delete [] m_hobby;

		// strlen() can't handle a nullptr so
		// we must check that first
		if (nullptr == c.m_hobby)
			m_hobby = nullptr;
		else
		{
			// now get the string length
			// and copy c.m_hobby to m_hobby
			long len = strlen(c.m_hobby); 
			if (len <= 0)
			{
				m_hobby = new char[1];
				m_hobby[0] = '\0';		
			}
			else
			{
				// allocate space for the new character array
				// +1 for the null character
				m_hobby = new char[len+1];
				// copy from c.m_hobby into m_hobby
				for(int i=0; i <= len; i++)
				{
					m_hobby[i] = c.m_hobby[i];
					if ('\0' == c.m_hobby[i])
						break;
				}
				// ensures that the C-style string is null terminated
				m_hobby[len] = '\0';
			}
		}
		


		// overwrites weight
		m_weight = c.m_weight;

		return *this;
	}

	// other functionality
	void Cow::showCow() const
	{
		using std::cout;
		using std::endl;
		// if m_hobby is the nullptr then we print
		// "no hobby" instead.
		if (m_hobby == nullptr)
			cout << "Name: " << m_name << endl
			 << "Hobby: " << "None" << endl
			 << "Weight: " << m_weight;
		else
			cout << "Name: " << m_name << endl
			 << "Hobby: " << m_hobby << endl
			 << "Weight: " << m_weight;
	}

}