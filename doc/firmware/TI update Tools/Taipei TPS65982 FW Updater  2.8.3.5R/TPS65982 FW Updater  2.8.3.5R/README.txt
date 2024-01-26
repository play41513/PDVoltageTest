TPS65982 FW Updater is a tool that allows users to update TPS65982 Firmware Image release by Action Star Technology Co., Ltd.
  
Open the Application and plug your device  to start the update.


#README


## [版號擴充碼說明]
F : 給工廠使用的版本
R : RD開發工程版本
T : 測試版本


Support software reset devices list:
- DS-UCB7(180) by 24K_V0063_68A275.BIN and later.
- DS-UCC7(190) by DS-UCC7_F0080_24K.bin and later.
- DS-UCC6 by DS-UCC7_F0080_24K.bin and later.


注意事項:
1. 接c to c cable時，關閉TPS65982電源的話，CC不會溝通，U2不會掛載，所以無法進行更新，故不可強制關TPS65982電源。
2. Start with version 2.7.0.0, change the update process, first update the main code, 
   then notify the firmware to update the backup code, and finally update the startup table.

