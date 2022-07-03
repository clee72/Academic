//Error.h
//Date: 2019/07/30
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms2

#ifndef AID_ERROR_H
#define AID_ERROR_H

namespace aid {

	class Error {
		char* errMsg;

	public:
		explicit Error(const char* errorMessage = nullptr);
		~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream&, const Error&);
}
#endif