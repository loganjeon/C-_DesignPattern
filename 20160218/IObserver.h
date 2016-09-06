struct IObserver
{
	virtual void onUpdate(void* data) = 0;
	virtual ~IObserver() {}
};
