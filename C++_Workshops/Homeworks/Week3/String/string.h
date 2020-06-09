#ifndef STRING_H
#define STRING_H

class String
{
	private:
		void setString(const char*);
		int _len; // cache length
		char* _array;
        int StringCompare(const String&) const;
		
	public:
        //constructors
		String();
		String(const char*);
		String(const String&);
		~String();

        //operators from notebook/choveret
		String& operator=(const String&);
		String operator+(const String&);
		char& operator[](int index);
		bool operator==(const String&) const;

        //my relational operators and methods that I defined
        bool operator<(const String&) const;
        bool operator>(const String&) const;
        bool operator<=(const String&) const;
        bool operator>=(const String&) const;
        bool operator!=(const String&) const;
        String& insert(int index, const String& str);

		//other methods from choveret
		int length() { return _len; }
		bool empty() { return length() == 0; }
		String substr(int start, int end);
		void print();
	};

#endif