#include <IwDebug.h>
#include <dpiInfo.h>
#include <iwgx.h>

namespace DPI
{
	int initCounter = 0;

	int32 dpiGetScreenDPI_iOS()
	{
		uint32 w = IwGxGetScreenWidth();
		uint32 h = IwGxGetScreenHeight();
		if (w<h)
		{
			uint32 i = w;w=h;h=i;
		}
		if (w == 480)
			return 163;
		if (w == 1024)
			return 132;
		if (w == 326)
			return 326;
		return 163;

		//const char* deviceID = s3eDeviceGetString(S3E_DEVICE_ID);
		//return 326; //Retina display 960x640
		//return 132; //iPad 1024x768
		//return 163; //old ipod/iphone; 480x320
	}

}

using namespace DPI;

void DPI::dpiInit()
{
	++initCounter;
	if (initCounter != 1)
		return;

	//IW_CLASS_REGISTER(CfthFont);
}

void DPI::dpiTerminate()
{
	--initCounter;
	if (initCounter < 0)
		IwAssertMsg(FREETYPE,false,("dpiTerminate doesn't match dpiInit"));
	if (initCounter != 0)
		return;
}

int32 DPI::dpiGetScreenDPI()
{
	int32 os = s3eDeviceGetInt(S3E_DEVICE_OS);
	switch (os)
	{
	case S3E_OS_ID_IPHONE:
		return dpiGetScreenDPI_iOS();
	default:
		break;
	}
	return 163;
}
