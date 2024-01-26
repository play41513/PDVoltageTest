//---------------------------------------------------------------------------
#include <windows.h>    // �w������USB�˸m�� *�n�� vcl.h ���sĶ
#include <SetupAPI.h> // �w������USB�˸m�� *�n�� vcl.h ���sĶ
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
	//DEBUG("[ �˸m�C�| ]");
	//--------------------------------------------------------------------------
	//   ����]�Ƹ�T
	hDevInfo = SetupDiGetClassDevs((LPGUID)&GUID_USB_HID,
	0,   //   Enumerator
	0,
	DIGCF_PRESENT | DIGCF_DEVICEINTERFACE );
	if   (hDevInfo   ==   INVALID_HANDLE_VALUE){
		//DEBUG("ERROR - SetupDiGetClassDevs()"); //   �d�߸�T����
	}
	else{
	//--------------------------------------------------------------------------
		SP_DEVICE_INTERFACE_DATA   ifdata;
		SP_DEVINFO_DATA            spdd;
		DeviceInfoData.cbSize   =   sizeof(SP_DEVINFO_DATA);
		for (i=0;SetupDiEnumDeviceInfo(hDevInfo, i, &DeviceInfoData);i++)	//   �T�|�C��USB�]��
		{
			ifdata.cbSize   =   sizeof(ifdata);
			if (SetupDiEnumDeviceInterfaces(								//   �T�|�ŦX��GUID���]�Ƥ���
			hDevInfo,           //   �]�Ƹ�T������X
			NULL,                         //   �����B�~���]�ƴy�z
			(LPGUID)&GUID_USB_HID,//GUID_CLASS_USB_DEVICE,                     //   GUID
			(ULONG)i,       //   �]�Ƹ�T���ت��]�ƧǸ�
			&ifdata))                 //   �]�Ƥ�����T
			{
				ULONG predictedLength   =   0;
				ULONG requiredLength   =   0;
				//   ���o�ӳ]�Ƥ������Ӹ`(�]�Ƹ��|)
				SetupDiGetInterfaceDeviceDetail(hDevInfo,         //   �]�Ƹ�T������X
					&ifdata,          //   �]�Ƥ�����T
					NULL,             //   �]�Ƥ����Ӹ`(�]�Ƹ��|)
					0,         	      //   ��X�w�İϤj�p
					&requiredLength,  //   ���ݭp���X�w�İϤj�p(�����γ]�w��)
					NULL);            //   �����B�~���]�ƴy�z
				//   ���o�ӳ]�Ƥ������Ӹ`(�]�Ƹ��|)
				predictedLength=requiredLength;
				pDetail = (PSP_INTERFACE_DEVICE_DETAIL_DATA)::GlobalAlloc(LMEM_ZEROINIT,   predictedLength);
				pDetail->cbSize   =   sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
				//
				ZeroMemory(&spdd, sizeof(spdd));
				spdd.cbSize = sizeof(spdd);

				if(SetupDiGetInterfaceDeviceDetail(hDevInfo,         //   �]�Ƹ�T������X
					&ifdata,             //   �]�Ƥ�����T
					pDetail,             //   �]�Ƥ����Ӹ`(�]�Ƹ��|)
					predictedLength,     //   ��X�w�İϤj�p
					&requiredLength,     //   ���ݭp���X�w�İϤj�p(�����γ]�w��)
					&spdd))               //   �����B�~���]�ƴy�z
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
						//DEBUG(SS+"�C�|����");
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
	//DEBUG("[ �˸m�C�| ]");
	//--------------------------------------------------------------------------
	//   ����]�Ƹ�T
	hDevInfo = SetupDiGetClassDevs((LPGUID)&GUID_USB_HID,
	0,   //   Enumerator
	0,
	DIGCF_PRESENT | DIGCF_DEVICEINTERFACE );
	if   (hDevInfo   ==   INVALID_HANDLE_VALUE){
		//DEBUG("ERROR - SetupDiGetClassDevs()"); //   �d�߸�T����
	}
	else{
	//--------------------------------------------------------------------------
		SP_DEVICE_INTERFACE_DATA   ifdata;
		SP_DEVINFO_DATA            spdd;
		DeviceInfoData.cbSize   =   sizeof(SP_DEVINFO_DATA);
		for (i=0;SetupDiEnumDeviceInfo(hDevInfo, i, &DeviceInfoData);i++)	//   �T�|�C��USB�]��
		{
			ifdata.cbSize   =   sizeof(ifdata);
			if (SetupDiEnumDeviceInterfaces(								//   �T�|�ŦX��GUID���]�Ƥ���
			hDevInfo,           //   �]�Ƹ�T������X
			NULL,                         //   �����B�~���]�ƴy�z
			(LPGUID)&GUID_USB_HID,//GUID_CLASS_USB_DEVICE,                     //   GUID
			(ULONG)i,       //   �]�Ƹ�T���ت��]�ƧǸ�
			&ifdata))                 //   �]�Ƥ�����T
			{
				ULONG predictedLength   =   0;
				ULONG requiredLength   =   0;
				//   ���o�ӳ]�Ƥ������Ӹ`(�]�Ƹ��|)
				SetupDiGetInterfaceDeviceDetail(hDevInfo,         //   �]�Ƹ�T������X
					&ifdata,          //   �]�Ƥ�����T
					NULL,             //   �]�Ƥ����Ӹ`(�]�Ƹ��|)
					0,         	      //   ��X�w�İϤj�p
					&requiredLength,  //   ���ݭp���X�w�İϤj�p(�����γ]�w��)
					NULL);            //   �����B�~���]�ƴy�z
				//   ���o�ӳ]�Ƥ������Ӹ`(�]�Ƹ��|)
				predictedLength=requiredLength;
				pDetail = (PSP_INTERFACE_DEVICE_DETAIL_DATA)::GlobalAlloc(LMEM_ZEROINIT,   predictedLength);
				pDetail->cbSize   =   sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
				//
				ZeroMemory(&spdd, sizeof(spdd));
				spdd.cbSize = sizeof(spdd);

				if(SetupDiGetInterfaceDeviceDetail(hDevInfo,         //   �]�Ƹ�T������X
					&ifdata,             //   �]�Ƥ�����T
					pDetail,             //   �]�Ƥ����Ӹ`(�]�Ƹ��|)
					predictedLength,     //   ��X�w�İϤj�p
					&requiredLength,     //   ���ݭp���X�w�İϤj�p(�����γ]�w��)
					&spdd))               //   �����B�~���]�ƴy�z
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
						//DEBUG(SS+"�C�|����");
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