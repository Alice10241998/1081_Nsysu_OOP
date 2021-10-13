#include <iostream>
#include <iomanip>
#include <sstream>

class Form 
{
	private:
		int prc;
		int fmt;
		double val;
	public:
		friend std::ostream& operator<<(std::ostream&, const Form&);

		Form operator()(double d)
		{
			val=d;
			return *this;
		}

		Form(int p = 6): prc(p), fmt(0) {}; //初始化
		
		~Form() {};

		Form& scientific() //科學記號
		{
			fmt = std::ios_base::scientific;
			return *this;
		};

		Form& fixed() //輸出小數點後有幾位數
		{
			fmt = std::ios_base::fixed;
			return *this;
		};

		Form & precision(int p) //輸出p位數
		{
			prc = p;
			return *this;
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f) 
{
	std::ostringstream s;

	s.precision(f.prc);
	s.setf((std::ios_base::fmtflags)f.fmt, std::ios_base::floatfield); //輸出方式
	s << f.val;

	return os << s.str();
}
