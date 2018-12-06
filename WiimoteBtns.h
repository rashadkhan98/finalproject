#ifndef WIIMOTEBTNS_H
#define WIIMOTEBTNS_H



class WiimoteBtns{
	private:
		int fd;
	public:
		WiimoteBtns();
		~WiimoteBtns();
		void Run();
		void ButtonEvent(int code, int value);
};
#endif
