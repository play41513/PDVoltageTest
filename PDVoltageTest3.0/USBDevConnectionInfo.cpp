//---------------------------------------------------------------------------
#include <windows.h>    // 安全移除USB裝置用 *要比 vcl.h 早編譯
#include <SetupAPI.h> // 安全移除USB裝置用 *要比 vcl.h 早編譯
#include <cfgmgr32.h>
#pragma hdrstop

#include "USBDevConnectionInfo.h"
#define BUFSIZE 2048   //For buf buffer size
//---------------------------------------------------------------------------

#pragma package(smart_init)
bool USBDevConnectionInfo::VPIDCheckUSBDev(AnsiString VID,AnsiString PID)
{
	VID = VID.LowerCase();
	PID = PID.LowerCase();
	HDEVINFO hDevInfo;
	SP_DEVINFO_DATA DeviceInfoData;
	DWORD i,j;
	AnsiString SS,USBPath;
	PSP_DEVICE_INTERFACE_DETAIL_DATA   pDetail   =NULL;
	GUID GUID_USB_HID =StringToGUID("{A5DCBF10-6530-11D2-901F-00C04FB951ED}");
	//DEBUG("[ 裝置列舉 ]");
	//--------------------------------------------------------------------------
	//   獲取設備資訊
	hDevInfo = SetupDiGetClassDevs((LPGUID)&GUID_USB_HID,
	0,   //   Enumerator
	0,
	DIGCF_PRESENT | DIGCF_DEVICEINTERFACE );
	if   (hDevInfo   ==   INVALID_HANDLE_VALUE){
		//DEBUG("ERROR - SetupDiGetClassDevs()"); //   查詢資訊失敗
	}
	else{
	//--------------------------------------------------------------------------
		SP_DEVICE_INTERFACE_DATA   ifdata;
		SP_DEVINFO_DATA            spdd;
		DeviceInfoData.cbSize   =   sizeof(SP_DEVINFO_DATA);
		for (i=0;SetupDiEnumDeviceInfo(hDevInfo, i, &DeviceInfoData);i++)	//   枚舉每個USB設備
		{
			ifdata.cbSize   =   sizeof(ifdata);
			if (SetupDiEnumDeviceInterfaces(								//   枚舉符合該GUID的設備介面
			hDevInfo,           //   設備資訊集控制碼
			NULL,                         //   不需額外的設備描述
			(LPGUID)&GUID_USB_HID,//GUID_CLASS_USB_DEVICE,                     //   GUID
			(ULONG)i,       //   設備資訊集�堛熙]備序號
			&ifdata))                 //   設備介面資訊
			{
				ULONG predictedLength   =   0;
				ULONG requiredLength   =   0;
				//   取得該設備介面的細節(設備路徑)
				SetupDiGetInterfaceDeviceDetail(hDevInfo,         //   設備資訊集控制碼
					&ifdata,          //   設備介面資訊
					NULL,             //   設備介面細節(設備路徑)
					0,         	      //   輸出緩衝區大小
					&requiredLength,  //   不需計算輸出緩衝區大小(直接用設定值)
					NULL);            //   不需額外的設備描述
				//   取得該設備介面的細節(設備路徑)
				predictedLength=requiredLength;
				pDetail = (PSP_INTERFACE_DEVICE_DETAIL_DATA)::GlobalAlloc(LMEM_ZEROINIT,   predictedLength);
				pDetail->cbSize   =   sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
				//
				ZeroMemory(&spdd, sizeof(spdd));
				spdd.cbSize = sizeof(spdd);

				if(SetupDiGetInterfaceDeviceDetail(hDevInfo,         //   設備資訊集控制碼
					&ifdata,             //   設備介面資訊
					pDetail,             //   設備介面細節(設備路徑)
					predictedLength,     //   輸出緩衝區大小
					&requiredLength,     //   不需計算輸出緩衝區大小(直接用設定值)
					&spdd))               //   不需額外的設備描述
				{
					try
					{
						/*char ch[512];
						for(j=0;j<predictedLength;j++)
							ch[j]=*(pDetail->DevicePath+8+j);*/
						SS = pDetail->DevicePath;
						//SS=ch;
						//DEBUG(SS);
						if(SS.Pos(VID)&&SS.Pos(PID))
						{
							GlobalFree(pDetail);
							SetupDiDestroyDeviceInfoList(hDevInfo);
							return true;
						}

					}
					catch(...)
					{
						//DEBUG(SS+"列舉失敗");
					}

				}
				else
				{
					//DEBUG("SetupDiGetInterfaceDeviceDetail F");
				}
				GlobalFree(pDetail);
			}
			else
			{
				//DEBUG("SetupDiEnumDeviceInterfaces F");
			}
		}
	}
	SetupDiDestroyDeviceInfoList(hDevInfo);
	return false;
}
bool USBDevConnectionInfo::VPIDCheckHUBDev(AnsiString VID,AnsiString PID)
{
	VID = VID.LowerCase();
	PID = PID.LowerCase();
	HDEVINFO hDevInfo;
	SP_DEVINFO_DATA DeviceInfoData;
	DWORD i,j;
	AnsiString SS,USBPath;
	PSP_DEVICE_INTERFACE_DETAIL_DATA   pDetail   =NULL;
	GUID GUID_USB_HID =StringToGUID("{F18A0E88-C30C-11D0-8815-00A0C906BED8}");
	//DEBUG("[ 裝置列舉 ]");
	//--------------------------------------------------------------------------
	//   獲取設備資訊
	hDevInfo = SetupDiGetClassDevs((LPGUID)&GUID_USB_HID,
	0,   //   Enumerator
	0,
	DIGCF_PRESENT | DIGCF_DEVICEINTERFACE );
	if   (hDevInfo   ==   INVALID_HANDLE_VALUE){
		//DEBUG("ERROR - SetupDiGetClassDevs()"); //   查詢資訊失敗
	}
	else{
	//--------------------------------------------------------------------------
		SP_DEVICE_INTERFACE_DATA   ifdata;
		SP_DEVINFO_DATA            spdd;
		DeviceInfoData.cbSize   =   sizeof(SP_DEVINFO_DATA);
		for (i=0;SetupDiEnumDeviceInfo(hDevInfo, i, &DeviceInfoData);i++)	//   枚舉每個USB設備
		{
			ifdata.cbSize   =   sizeof(ifdata);
			if (SetupDiEnumDeviceInterfaces(								//   枚舉符合該GUID的設備介面
			hDevInfo,           //   設備資訊集控制碼
			NULL,                         //   不需額外的設備描述
			(LPGUID)&GUID_USB_HID,//GUID_CLASS_USB_DEVICE,                     //   GUID
			(ULONG)i,       //   設備資訊集�堛熙]備序號
			&ifdata))                 //   設備介面資訊
			{
				ULONG predictedLength   =   0;
				ULONG requiredLength   =   0;
				//   取得該設備介面的細節(設備路徑)
				SetupDiGetInterfaceDeviceDetail(hDevInfo,         //   設備資訊集控制碼
					&ifdata,          //   設備介面資訊
					NULL,             //   設備介面細節(設備路徑)
					0,         	      //   輸出緩衝區大小
					&requiredLength,  //   不需計算輸出緩衝區大小(直接用設定值)
					NULL);            //   不需額外的設備描述
				//   取得該設備介面的細節(設備路徑)
				predictedLength=requiredLength;
				pDetail = (PSP_INTERFACE_DEVICE_DETAIL_DATA)::GlobalAlloc(LMEM_ZEROINIT,   predictedLength);
				pDetail->cbSize   =   sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
				//
				ZeroMemory(&spdd, sizeof(spdd));
				spdd.cbSize = sizeof(spdd);

				if(SetupDiGetInterfaceDeviceDetail(hDevInfo,         //   設備資訊集控制碼
					&ifdata,             //   設備介面資訊
					pDetail,             //   設備介面細節(設備路徑)
					predictedLength,     //   輸出緩衝區大小
					&requiredLength,     //   不需計算輸出緩衝區大小(直接用設定值)
					&spdd))               //   不需額外的設備描述
				{
					try
					{
						/*char ch[512];
						for(j=0;j<predictedLength;j++)
							ch[j]=*(pDetail->DevicePath+8+j);
						SS=ch;*/
						SS = pDetail->DevicePath;
						//DEBUG(SS);
						if(SS.Pos(VID)&&SS.Pos(PID))
						{
							GlobalFree(pDetail);
							SetupDiDestroyDeviceInfoList(hDevInfo);
							return true;
						}

					}
					catch(...)
					{
						//DEBUG(SS+"列舉失敗");
					}

				}
				else
				{
					//DEBUG("SetupDiGetInterfaceDeviceDetail F");
				}
				GlobalFree(pDetail);
			}
			else
			{
				//DEBUG("SetupDiEnumDeviceInterfaces F");
			}
		}
	}
	SetupDiDestroyDeviceInfoList(hDevInfo);
	return false;
}
