//---------------------------------------------------------------------------
#include <StrUtils.hpp>
#include "usbioctl.h"
#include "malloc.h"
#include "vndrlist.h"
#include "stdio.h"
#include <vcl.h>
#ifndef USBDevConnectionInfoH
#define USBDevConnectionInfoH
//---------------------------------------------------------------------------
class USBDevConnectionInfo
{
public:
	bool VPIDCheckUSBDev(AnsiString VID,AnsiString PID);
	bool VPIDCheckHUBDev(AnsiString VID,AnsiString PID);
private:
};
#endif
