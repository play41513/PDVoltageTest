object FrmMain: TFrmMain
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  ClientHeight = 548
  ClientWidth = 962
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 962
    Height = 548
    Align = alClient
    TabOrder = 0
    object pl_Set_Switch: TPanel
      Left = 1
      Top = 280
      Width = 960
      Height = 10
      Align = alBottom
      Caption = '^'
      Color = clSkyBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 0
      OnClick = pl_Set_SwitchClick
    end
    object pl_Set: TPanel
      Left = 1
      Top = 290
      Width = 960
      Height = 257
      Align = alBottom
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      OnResize = pl_SetResize
      object pl_set_5: TPanel
        Left = 1
        Top = 223
        Width = 958
        Height = 31
        Align = alTop
        Enabled = False
        TabOrder = 4
        object plSetVolTitle_5: TPanel
          Left = 1
          Top = 1
          Width = 216
          Height = 29
          Hint = 'H'
          Align = alLeft
          Caption = '20V'
          Color = clGradientActiveCaption
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object edt_min5: TEdit
          Tag = 20
          Left = 249
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 1
          Text = '20.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object pl_ckb5_2: TPanel
          Tag = 2
          Left = 217
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
        object edt_max5: TEdit
          Tag = 20
          Left = 373
          Top = 1
          Width = 92
          Height = 29
          Hint = '2'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 3
          Text = '20.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel37: TPanel
          Tag = 1
          Left = 341
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Caption = '~'
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 4
        end
        object plFullLoad_5: TPanel
          Tag = 1
          Left = 465
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 5
          OnClick = ckbAuto1Click
        end
        object edt_load_min5: TEdit
          Tag = 20
          Left = 497
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 6
          Text = '19.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel54: TPanel
          Tag = 1
          Left = 589
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Caption = '~'
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
        object edt_load_max5: TEdit
          Tag = 20
          Left = 621
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 8
          Text = '21.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel40: TPanel
          Tag = 1
          Left = 713
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 9
          OnClick = ckbAuto1Click
        end
        object edtSetCurrent5: TEdit
          Tag = 5
          Left = 745
          Top = 1
          Width = 212
          Height = 29
          Hint = '1'
          Align = alClient
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 10
          Text = '3.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
      end
      object pl_set_4: TPanel
        Left = 1
        Top = 192
        Width = 958
        Height = 31
        Align = alTop
        Enabled = False
        TabOrder = 3
        object plSetVolTitle_4: TPanel
          Left = 1
          Top = 1
          Width = 216
          Height = 29
          Hint = 'H'
          Align = alLeft
          Caption = '15V'
          Color = clGradientActiveCaption
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object edt_min4: TEdit
          Tag = 15
          Left = 249
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 1
          Text = '15.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object pl_ckb4_2: TPanel
          Tag = 2
          Left = 217
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
        object edt_max4: TEdit
          Tag = 15
          Left = 373
          Top = 1
          Width = 92
          Height = 29
          Hint = '2'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 3
          Text = '15.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel31: TPanel
          Tag = 1
          Left = 341
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Caption = '~'
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 4
        end
        object plFullLoad_4: TPanel
          Tag = 1
          Left = 465
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 5
          OnClick = ckbAuto1Click
        end
        object edt_load_min4: TEdit
          Tag = 15
          Left = 497
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 6
          Text = '14.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel53: TPanel
          Tag = 1
          Left = 589
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Caption = '~'
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
        object edt_load_max4: TEdit
          Tag = 15
          Left = 621
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 8
          Text = '16.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel28: TPanel
          Tag = 1
          Left = 713
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 9
          OnClick = ckbAuto1Click
        end
        object edtSetCurrent4: TEdit
          Tag = 5
          Left = 745
          Top = 1
          Width = 212
          Height = 29
          Hint = '1'
          Align = alClient
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 10
          Text = '3.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
      end
      object pl_set_3: TPanel
        Left = 1
        Top = 161
        Width = 958
        Height = 31
        Align = alTop
        Enabled = False
        TabOrder = 2
        object plSetVolTitle_3: TPanel
          Left = 1
          Top = 1
          Width = 216
          Height = 29
          Hint = 'H'
          Align = alLeft
          Caption = '12V'
          Color = clGradientActiveCaption
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object edt_min3: TEdit
          Tag = 12
          Left = 249
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 1
          Text = '12.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object pl_ckb3_2: TPanel
          Tag = 2
          Left = 217
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
        object edt_max3: TEdit
          Tag = 12
          Left = 373
          Top = 1
          Width = 92
          Height = 29
          Hint = '2'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 3
          Text = '12.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel26: TPanel
          Tag = 1
          Left = 341
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Caption = '~'
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 4
        end
        object plFullLoad_3: TPanel
          Tag = 1
          Left = 465
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 5
          OnClick = ckbAuto1Click
        end
        object edt_load_min3: TEdit
          Tag = 12
          Left = 497
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 6
          Text = '11.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel52: TPanel
          Tag = 1
          Left = 589
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Caption = '~'
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
        object edt_load_max3: TEdit
          Tag = 12
          Left = 621
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 8
          Text = '13.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel23: TPanel
          Tag = 1
          Left = 713
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 9
          OnClick = ckbAuto1Click
        end
        object edtSetCurrent3: TEdit
          Tag = 5
          Left = 745
          Top = 1
          Width = 212
          Height = 29
          Hint = '1'
          Align = alClient
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 10
          Text = '3.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
      end
      object pl_set_2: TPanel
        Left = 1
        Top = 130
        Width = 958
        Height = 31
        Align = alTop
        Enabled = False
        TabOrder = 1
        object plSetVolTitle_2: TPanel
          Left = 1
          Top = 1
          Width = 216
          Height = 29
          Hint = 'H'
          Align = alLeft
          Caption = '9V'
          Color = clGradientActiveCaption
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object edt_min2: TEdit
          Tag = 9
          Left = 249
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 1
          Text = '9.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object pl_ckb2_2: TPanel
          Tag = 2
          Left = 217
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
        object edt_max2: TEdit
          Tag = 9
          Left = 373
          Top = 1
          Width = 92
          Height = 29
          Hint = '2'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 3
          Text = '9.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel21: TPanel
          Tag = 1
          Left = 341
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Caption = '~'
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 4
        end
        object plFullLoad_2: TPanel
          Tag = 1
          Left = 465
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 5
          OnClick = ckbAuto1Click
        end
        object edt_load_min2: TEdit
          Tag = 9
          Left = 497
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 6
          Text = '8.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel51: TPanel
          Tag = 1
          Left = 589
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Caption = '~'
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
        object edt_load_max2: TEdit
          Tag = 9
          Left = 621
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 8
          Text = '10.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel18: TPanel
          Tag = 1
          Left = 713
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 9
          OnClick = ckbAuto1Click
        end
        object edtSetCurrent2: TEdit
          Tag = 5
          Left = 745
          Top = 1
          Width = 212
          Height = 29
          Hint = '1'
          Align = alClient
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 10
          Text = '3.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
      end
      object pl_set_1: TPanel
        Left = 1
        Top = 99
        Width = 958
        Height = 31
        Align = alTop
        Enabled = False
        TabOrder = 0
        object plSetVolTitle_1: TPanel
          Left = 1
          Top = 1
          Width = 216
          Height = 29
          Hint = 'H'
          Align = alLeft
          Caption = '5V'
          Color = clGradientActiveCaption
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object edt_min1: TEdit
          Tag = 5
          Left = 249
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 1
          Text = '5.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object pl_ckb1_2: TPanel
          Tag = 2
          Left = 217
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
        object edt_max1: TEdit
          Tag = 5
          Left = 373
          Top = 1
          Width = 92
          Height = 29
          Hint = '2'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 3
          Text = '5.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel16: TPanel
          Tag = 1
          Left = 341
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Caption = '~'
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 4
        end
        object plFullLoad_1: TPanel
          Tag = 1
          Left = 465
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 5
          OnClick = ckbAuto1Click
        end
        object edt_load_min1: TEdit
          Tag = 5
          Left = 497
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 6
          Text = '4.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel50: TPanel
          Tag = 1
          Left = 589
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Caption = '~'
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
        object edt_load_max1: TEdit
          Tag = 5
          Left = 621
          Top = 1
          Width = 92
          Height = 29
          Hint = '1'
          Align = alLeft
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 8
          Text = '6.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel13: TPanel
          Tag = 1
          Left = 713
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 9
          OnClick = ckbAuto1Click
        end
        object edtSetCurrent1: TEdit
          Tag = 5
          Left = 745
          Top = 1
          Width = 212
          Height = 29
          Hint = '1'
          Align = alClient
          Alignment = taCenter
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 10
          Text = '3.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
      end
      object Panel63: TPanel
        Left = 1
        Top = 68
        Width = 958
        Height = 31
        Align = alTop
        Color = clTeal
        ParentBackground = False
        TabOrder = 5
        object plSetVolTitle_0: TPanel
          Left = 1
          Top = 1
          Width = 216
          Height = 29
          Align = alLeft
          Caption = 'PD'#37327#28204#38651#22739
          Color = clTeal
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #27161#26999#39636
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object plSetNoLoadVolTitle: TPanel
          Left = 249
          Top = 1
          Width = 216
          Height = 29
          Align = alLeft
          Caption = #31354#36617#38651#22739#31684#22285'(V)'
          Color = clTeal
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -20
          Font.Name = #27161#26999#39636
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
        end
        object plSetFullLoadVolTitle: TPanel
          Left = 497
          Top = 1
          Width = 216
          Height = 29
          Align = alLeft
          Caption = #28415#36617#38651#22739#31684#22285'(V)'
          Color = clTeal
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -20
          Font.Name = #27161#26999#39636
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
        object Panel15: TPanel
          Left = 217
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Color = clTeal
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
        end
        object Panel17: TPanel
          Left = 465
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Color = clTeal
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 4
        end
        object plLoadCurr: TPanel
          Left = 745
          Top = 1
          Width = 212
          Height = 29
          Hint = 'H'
          Align = alClient
          Caption = #36000#36617#38651#27969'(A)'
          Color = clTeal
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #27161#26999#39636
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 5
        end
        object Panel14: TPanel
          Left = 713
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Color = clTeal
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 6
        end
      end
      object Panel22: TPanel
        Left = 1
        Top = 1
        Width = 958
        Height = 67
        Align = alTop
        Caption = 'Panel22'
        TabOrder = 6
        object Panel71: TPanel
          Left = 1
          Top = 1
          Width = 956
          Height = 64
          Align = alTop
          TabOrder = 0
          object Panel20: TPanel
            Tag = 1
            Left = 1
            Top = 1
            Width = 954
            Height = 62
            Align = alClient
            BevelOuter = bvNone
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlue
            Font.Height = -27
            Font.Name = 'Times New Roman'
            Font.Style = [fsBold]
            ParentBackground = False
            ParentFont = False
            TabOrder = 0
            OnClick = ckbAuto1Click
            object Panel25: TPanel
              Tag = 1
              Left = 0
              Top = 38
              Width = 954
              Height = 24
              Align = alBottom
              BevelOuter = bvNone
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlue
              Font.Height = -27
              Font.Name = 'Times New Roman'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 0
              OnClick = ckbAuto1Click
              object lbVoltageAuto: TLabel
                Left = 642
                Top = 0
                Width = 19
                Height = 24
                Align = alLeft
                Caption = ' V'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBackground
                Font.Height = -20
                Font.Name = 'Times New Roman'
                Font.Style = [fsBold]
                ParentFont = False
                ExplicitHeight = 23
              end
              object ckbVPIDAuto: TCheckBox
                Left = 10
                Top = 0
                Width = 145
                Height = 24
                Hint = #20597#28204#21040#24453#28204#29289'(VPID'#21516#21491#37002#35373#23450')'#25554#20837#26178' '#33258#21205#28204#35430#65292#36895#24230#20381#38651#33126#25928#33021#32780#23450#12290
                Align = alLeft
                BiDiMode = bdLeftToRight
                Caption = 'VPID Auto'
                Color = clCream
                Enabled = False
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -20
                Font.Name = 'Times New Roman'
                Font.Style = []
                ParentBiDiMode = False
                ParentColor = False
                ParentFont = False
                ParentShowHint = False
                ShowHint = True
                TabOrder = 0
                OnClick = ckbVPIDAutoClick
              end
              object pl_DutVPID: TPanel
                Left = 155
                Top = 0
                Width = 240
                Height = 24
                Align = alLeft
                BevelOuter = bvNone
                TabOrder = 1
                object plPidTitle: TPanel
                  Left = 117
                  Top = 0
                  Width = 45
                  Height = 24
                  Align = alLeft
                  Caption = 'PID '
                  Color = clActiveCaption
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Times New Roman'
                  Font.Style = []
                  ParentBackground = False
                  ParentFont = False
                  TabOrder = 0
                end
                object plVidTitle: TPanel
                  Left = 0
                  Top = 0
                  Width = 45
                  Height = 24
                  Align = alLeft
                  Caption = 'VID'
                  Color = clActiveCaption
                  Font.Charset = ANSI_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Times New Roman'
                  Font.Style = []
                  ParentBackground = False
                  ParentFont = False
                  TabOrder = 1
                end
                object edtVID: TEdit
                  Left = 45
                  Top = 0
                  Width = 72
                  Height = 24
                  Align = alLeft
                  Alignment = taCenter
                  Enabled = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeMode = imSAlpha
                  ParentFont = False
                  TabOrder = 2
                  Text = '0000'
                  OnChange = edtVIDChange
                end
                object edtPID: TEdit
                  Left = 162
                  Top = 0
                  Width = 72
                  Height = 24
                  Align = alLeft
                  Alignment = taCenter
                  Enabled = False
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ImeMode = imSAlpha
                  ParentFont = False
                  TabOrder = 3
                  Text = '0000'
                  OnChange = edtVIDChange
                end
              end
              object edtVoltageAutoValue: TEdit
                Tag = 5
                Left = 550
                Top = 0
                Width = 92
                Height = 24
                Hint = '1'
                Align = alLeft
                Alignment = taCenter
                Enabled = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlack
                Font.Height = -20
                Font.Name = 'Times New Roman'
                Font.Style = []
                ImeMode = imSAlpha
                ParentFont = False
                TabOrder = 2
                Text = '4.00'
                OnChange = edt_min1Change
                OnExit = edt_min1Exit
                ExplicitHeight = 30
              end
              object ckbVoltageAuto: TCheckBox
                Left = 405
                Top = 0
                Width = 145
                Height = 24
                Hint = #20597#28204#21040#24453#28204#29289'(VPID'#21516#21491#37002#35373#23450')'#25554#20837#26178' '#33258#21205#28204#35430#65292#36895#24230#20381#38651#33126#25928#33021#32780#23450#12290
                Align = alLeft
                BiDiMode = bdLeftToRight
                Caption = 'Voltage Auto'
                Color = clCream
                Enabled = False
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -20
                Font.Name = 'Times New Roman'
                Font.Style = []
                ParentBiDiMode = False
                ParentColor = False
                ParentFont = False
                ParentShowHint = False
                ShowHint = True
                TabOrder = 3
                OnClick = ckbVPIDAutoClick
              end
              object Panel8: TPanel
                Left = 395
                Top = 0
                Width = 10
                Height = 24
                Align = alLeft
                BevelOuter = bvNone
                TabOrder = 4
              end
              object Panel10: TPanel
                Left = 0
                Top = 0
                Width = 10
                Height = 24
                Align = alLeft
                BevelOuter = bvNone
                TabOrder = 5
              end
            end
            object Panel9: TPanel
              Left = 0
              Top = 0
              Width = 954
              Height = 32
              Align = alTop
              Caption = 'Panel9'
              TabOrder = 1
              object edtPassWord: TEdit
                Left = 1
                Top = 1
                Width = 726
                Height = 30
                Align = alClient
                Alignment = taCenter
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clBlue
                Font.Height = -21
                Font.Name = 'Times New Roman'
                Font.Style = []
                ImeMode = imSAlpha
                ParentFont = False
                PasswordChar = '*'
                TabOrder = 0
                TextHint = 'PASSWORD'
                OnEnter = edtPassWordEnter
                OnKeyPress = edtPassWordKeyPress
                ExplicitHeight = 31
              end
              object btnSet: TBitBtn
                Left = 727
                Top = 1
                Width = 226
                Height = 30
                Align = alRight
                Caption = 'ENTER'
                DoubleBuffered = True
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -24
                Font.Name = 'Times New Roman'
                Font.Style = []
                ParentDoubleBuffered = False
                ParentFont = False
                TabOrder = 1
                OnClick = btnSetClick
              end
            end
          end
        end
        object pl_Auto: TPanel
          Left = 727
          Top = 65
          Width = 230
          Height = 1
          Align = alRight
          Color = clWhite
          ParentBackground = False
          TabOrder = 1
        end
      end
    end
    object Panel27: TPanel
      Left = 1
      Top = 1
      Width = 722
      Height = 279
      Align = alClient
      Caption = 'Panel27'
      TabOrder = 2
      object Panel7: TPanel
        Left = 1
        Top = 232
        Width = 720
        Height = 46
        Align = alBottom
        TabOrder = 0
        object btnStart: TBitBtn
          Left = 120
          Top = 1
          Width = 599
          Height = 44
          Align = alClient
          Caption = 'Start'
          DoubleBuffered = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentDoubleBuffered = False
          ParentFont = False
          TabOrder = 0
          OnClick = btnStartClick
        end
        object plIniName: TPanel
          Left = 1
          Top = 1
          Width = 119
          Height = 44
          Align = alLeft
          BevelOuter = bvNone
          Caption = '-'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGreen
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
        end
        object plMAC: TPanel
          Left = 120
          Top = 1
          Width = 0
          Height = 44
          Align = alLeft
          BevelOuter = bvNone
          Caption = 'MAC'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -33
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
      end
      object Panel19: TPanel
        Left = 1
        Top = 1
        Width = 120
        Height = 231
        Align = alLeft
        TabOrder = 1
        object Panel41: TPanel
          Left = 1
          Top = 185
          Width = 118
          Height = 45
          Align = alBottom
          Caption = #28415#36617
          Color = clGradientInactiveCaption
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object Panel42: TPanel
          Left = 1
          Top = 1
          Width = 118
          Height = 18
          Align = alTop
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          OnClick = ckbAuto1Click
        end
        object Panel43: TPanel
          Tag = 20
          Left = 1
          Top = 19
          Width = 118
          Height = 121
          Hint = '4'
          Align = alClient
          Caption = 'PD'#38651#22739
          Color = clGradientInactiveCaption
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -33
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = plSetVoltage1Click
          object Label1: TLabel
            Tag = 20
            Left = 8
            Top = 96
            Width = 4
            Height = 16
            Alignment = taCenter
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
        end
        object Panel45: TPanel
          Left = 1
          Top = 140
          Width = 118
          Height = 45
          Align = alBottom
          Caption = #31354#36617
          Color = clGradientInactiveCaption
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
        end
      end
      object Panel2: TPanel
        Left = 121
        Top = 1
        Width = 120
        Height = 231
        Align = alLeft
        ParentBackground = False
        TabOrder = 2
        object pl_read_5v_voltage: TPanel
          Left = 1
          Top = 140
          Width = 118
          Height = 45
          Align = alBottom
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object ckbAuto1: TPanel
          Tag = 1
          Left = 1
          Top = 1
          Width = 118
          Height = 18
          Hint = '0'
          Align = alTop
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          OnClick = ckbAuto1Click
        end
        object plSetVoltage1: TPanel
          Tag = 5
          Left = 1
          Top = 19
          Width = 118
          Height = 121
          Hint = '0'
          Align = alClient
          Caption = '5V'
          Color = clCream
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -33
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = plSetVoltage1Click
        end
        object pl_full_load_voltage5: TPanel
          Left = 1
          Top = 185
          Width = 118
          Height = 45
          Align = alBottom
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
        end
      end
      object Panel3: TPanel
        Left = 241
        Top = 1
        Width = 120
        Height = 231
        Align = alRight
        TabOrder = 3
        object pl_read_9v_voltage: TPanel
          Left = 1
          Top = 140
          Width = 118
          Height = 45
          Align = alBottom
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object ckbAuto2: TPanel
          Tag = 2
          Left = 1
          Top = 1
          Width = 118
          Height = 18
          Hint = '1'
          Align = alTop
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          OnClick = ckbAuto1Click
        end
        object plSetVoltage2: TPanel
          Tag = 9
          Left = 1
          Top = 19
          Width = 118
          Height = 121
          Hint = '1'
          Align = alClient
          Caption = '9V'
          Color = clCream
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -33
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = plSetVoltage1Click
        end
        object pl_full_load_voltage9: TPanel
          Left = 1
          Top = 185
          Width = 118
          Height = 45
          Align = alBottom
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
        end
      end
      object Panel4: TPanel
        Left = 361
        Top = 1
        Width = 120
        Height = 231
        Align = alRight
        TabOrder = 4
        object pl_read_12v_voltage: TPanel
          Left = 1
          Top = 140
          Width = 118
          Height = 45
          Align = alBottom
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object ckbAuto3: TPanel
          Left = 1
          Top = 1
          Width = 118
          Height = 18
          Hint = '2'
          Align = alTop
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          OnClick = ckbAuto1Click
        end
        object plSetVoltage3: TPanel
          Tag = 12
          Left = 1
          Top = 19
          Width = 118
          Height = 121
          Hint = '2'
          Align = alClient
          Caption = '12V'
          Color = clCream
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -33
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = plSetVoltage1Click
        end
        object pl_full_load_voltage12: TPanel
          Left = 1
          Top = 185
          Width = 118
          Height = 45
          Align = alBottom
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
        end
      end
      object Panel5: TPanel
        Left = 481
        Top = 1
        Width = 120
        Height = 231
        Align = alRight
        TabOrder = 5
        object pl_read_15v_voltage: TPanel
          Left = 1
          Top = 140
          Width = 118
          Height = 45
          Align = alBottom
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object ckbAuto4: TPanel
          Left = 1
          Top = 1
          Width = 118
          Height = 18
          Hint = '3'
          Align = alTop
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          OnClick = ckbAuto1Click
        end
        object plSetVoltage4: TPanel
          Tag = 15
          Left = 1
          Top = 19
          Width = 118
          Height = 121
          Hint = '3'
          Align = alClient
          Caption = '15V'
          Color = clCream
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -33
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = plSetVoltage1Click
        end
        object pl_full_load_voltage15: TPanel
          Left = 1
          Top = 185
          Width = 118
          Height = 45
          Align = alBottom
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
        end
      end
      object Panel6: TPanel
        Left = 601
        Top = 1
        Width = 120
        Height = 231
        Align = alRight
        TabOrder = 6
        object pl_read_20v_voltage: TPanel
          Left = 1
          Top = 140
          Width = 118
          Height = 45
          Align = alBottom
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object ckbAuto5: TPanel
          Left = 1
          Top = 1
          Width = 118
          Height = 18
          Hint = '4'
          Align = alTop
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          OnClick = ckbAuto1Click
        end
        object plSetVoltage5: TPanel
          Tag = 20
          Left = 1
          Top = 19
          Width = 118
          Height = 121
          Hint = '4'
          Align = alClient
          Caption = '20V'
          Color = clCream
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -33
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = plSetVoltage1Click
        end
        object pl_full_load_voltage20: TPanel
          Left = 1
          Top = 185
          Width = 118
          Height = 45
          Align = alBottom
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -27
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
        end
      end
    end
    object plResult: TPanel
      Left = 723
      Top = 1
      Width = 238
      Height = 279
      Align = alRight
      Caption = 'Wait...'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -33
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 3
      OnDblClick = plResultDblClick
      object lbLOGStatus: TLabel
        Left = 6
        Top = 2
        Width = 5
        Height = 22
        Color = clRed
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -20
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
    end
  end
  object moDebug: TMemo
    Left = 962
    Top = 0
    Width = 0
    Height = 548
    Align = alRight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
    OnChange = moDebugChange
  end
  object TimerMsg: TTimer
    Interval = 10
    OnTimer = TimerMsgTimer
    Left = 24
    Top = 16
  end
end
