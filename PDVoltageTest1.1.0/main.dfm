object FrmMain: TFrmMain
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  ClientHeight = 460
  ClientWidth = 625
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 615
    Height = 460
    Align = alClient
    TabOrder = 0
    object Panel2: TPanel
      Left = 1
      Top = 1
      Width = 120
      Height = 157
      Align = alLeft
      ParentBackground = False
      TabOrder = 0
      object pl_read_5v_voltage: TPanel
        Left = 1
        Top = 111
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
      object pl_Auto5V: TPanel
        Tag = 1
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
        OnClick = pl_Auto5VClick
      end
      object plSet5V: TPanel
        Tag = 5
        Left = 1
        Top = 19
        Width = 118
        Height = 92
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
        OnClick = plSet5VClick
        object lbRange1: TLabel
          Tag = 5
          Left = 44
          Top = 112
          Width = 4
          Height = 16
          Alignment = taCenter
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          ParentShowHint = False
          ShowHint = False
        end
      end
    end
    object Panel3: TPanel
      Left = 121
      Top = 1
      Width = 120
      Height = 157
      Align = alLeft
      TabOrder = 1
      object pl_read_9v_voltage: TPanel
        Left = 1
        Top = 111
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
      object pl_Auto9V: TPanel
        Tag = 2
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
        OnClick = pl_Auto5VClick
      end
      object plSet9V: TPanel
        Tag = 9
        Left = 1
        Top = 19
        Width = 118
        Height = 92
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
        OnClick = plSet5VClick
        object lbRange2: TLabel
          Tag = 9
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
    end
    object Panel4: TPanel
      Left = 241
      Top = 1
      Width = 120
      Height = 157
      Align = alLeft
      TabOrder = 2
      object pl_read_12v_voltage: TPanel
        Left = 1
        Top = 111
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
      object pl_Auto12V: TPanel
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
        OnClick = pl_Auto5VClick
      end
      object plSet12V: TPanel
        Tag = 12
        Left = 1
        Top = 19
        Width = 118
        Height = 92
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
        OnClick = plSet5VClick
        object lbRange3: TLabel
          Tag = 12
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
    end
    object Panel5: TPanel
      Left = 361
      Top = 1
      Width = 120
      Height = 157
      Align = alLeft
      TabOrder = 3
      object pl_read_15v_voltage: TPanel
        Left = 1
        Top = 111
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
      object pl_Auto15V: TPanel
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
        OnClick = pl_Auto5VClick
      end
      object plSet15V: TPanel
        Tag = 15
        Left = 1
        Top = 19
        Width = 118
        Height = 92
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
        OnClick = plSet5VClick
        object lbRange4: TLabel
          Tag = 15
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
    end
    object Panel6: TPanel
      Left = 481
      Top = 1
      Width = 120
      Height = 157
      Align = alLeft
      TabOrder = 4
      object pl_read_20v_voltage: TPanel
        Left = 1
        Top = 111
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
      object pl_Auto20V: TPanel
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
        OnClick = pl_Auto5VClick
      end
      object plSet20V: TPanel
        Tag = 20
        Left = 1
        Top = 19
        Width = 118
        Height = 92
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
        OnClick = plSet5VClick
        object lbRange5: TLabel
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
    end
    object Panel7: TPanel
      Left = 1
      Top = 158
      Width = 613
      Height = 46
      Align = alBottom
      TabOrder = 5
      object btnStart: TBitBtn
        Left = 1
        Top = 1
        Width = 611
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
    end
    object pl_Set_Switch: TPanel
      Left = 1
      Top = 204
      Width = 613
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
      TabOrder = 6
      OnClick = pl_Set_SwitchClick
    end
    object pl_Set: TPanel
      Left = 1
      Top = 214
      Width = 613
      Height = 245
      Align = alBottom
      Color = clWhite
      ParentBackground = False
      TabOrder = 7
      object Panel71: TPanel
        Left = 1
        Top = 1
        Width = 611
        Height = 32
        Align = alTop
        TabOrder = 0
        object edtPassWord: TEdit
          Left = 1
          Top = 1
          Width = 461
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
          ExplicitHeight = 31
        end
        object btnSet: TBitBtn
          Left = 462
          Top = 1
          Width = 148
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
      object pl_set_5: TPanel
        Left = 1
        Top = 215
        Width = 611
        Height = 31
        Align = alTop
        Enabled = False
        TabOrder = 1
        object plAD0: TPanel
          Left = 1
          Top = 1
          Width = 168
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
          Left = 321
          Top = 1
          Width = 128
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
        object pl_ckb5_1: TPanel
          Tag = 1
          Left = 169
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Caption = 'V'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = pl_ckb1_1Click
        end
        object pl_ckb5_2: TPanel
          Tag = 2
          Left = 289
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
          TabOrder = 3
          OnClick = pl_ckb1_1Click
        end
        object edt_max5: TEdit
          Tag = 20
          Left = 481
          Top = 1
          Width = 128
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
          TabOrder = 4
          Text = '20.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel37: TPanel
          Tag = 1
          Left = 449
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
          TabOrder = 5
        end
        object edt_Pi5: TEdit
          Tag = 20
          Left = 201
          Top = 1
          Width = 88
          Height = 29
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
          Text = '5'
          ExplicitHeight = 35
        end
        object plPI5: TPanel
          Tag = 2
          Left = 257
          Top = 6
          Width = 26
          Height = 23
          BevelOuter = bvNone
          Caption = '%'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
      end
      object pl_set_4: TPanel
        Left = 1
        Top = 184
        Width = 611
        Height = 31
        Align = alTop
        Enabled = False
        TabOrder = 2
        object Panel13: TPanel
          Left = 1
          Top = 1
          Width = 168
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
          Left = 321
          Top = 1
          Width = 128
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
        object pl_ckb4_1: TPanel
          Tag = 1
          Left = 169
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Caption = 'V'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = pl_ckb1_1Click
        end
        object pl_ckb4_2: TPanel
          Tag = 2
          Left = 289
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
          TabOrder = 3
          OnClick = pl_ckb1_1Click
        end
        object edt_max4: TEdit
          Tag = 15
          Left = 481
          Top = 1
          Width = 128
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
          TabOrder = 4
          Text = '15.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel31: TPanel
          Tag = 1
          Left = 449
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
          TabOrder = 5
        end
        object edt_Pi4: TEdit
          Tag = 15
          Left = 201
          Top = 1
          Width = 88
          Height = 29
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
          Text = '5'
          ExplicitHeight = 35
        end
        object plPI4: TPanel
          Tag = 2
          Left = 257
          Top = 6
          Width = 26
          Height = 23
          BevelOuter = bvNone
          Caption = '%'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
      end
      object pl_set_3: TPanel
        Left = 1
        Top = 153
        Width = 611
        Height = 31
        Align = alTop
        Enabled = False
        TabOrder = 3
        object Panel18: TPanel
          Left = 1
          Top = 1
          Width = 168
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
          Left = 321
          Top = 1
          Width = 128
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
        object pl_ckb3_1: TPanel
          Tag = 1
          Left = 169
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Caption = 'V'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = pl_ckb1_1Click
        end
        object pl_ckb3_2: TPanel
          Tag = 2
          Left = 289
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
          TabOrder = 3
          OnClick = pl_ckb1_1Click
        end
        object edt_max3: TEdit
          Tag = 12
          Left = 481
          Top = 1
          Width = 128
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
          TabOrder = 4
          Text = '12.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel26: TPanel
          Tag = 1
          Left = 449
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
          TabOrder = 5
        end
        object edt_Pi3: TEdit
          Tag = 12
          Left = 201
          Top = 1
          Width = 88
          Height = 29
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
          Text = '5'
          ExplicitHeight = 35
        end
        object plPI3: TPanel
          Tag = 2
          Left = 257
          Top = 6
          Width = 26
          Height = 23
          BevelOuter = bvNone
          Caption = '%'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
      end
      object pl_set_2: TPanel
        Left = 1
        Top = 122
        Width = 611
        Height = 31
        Align = alTop
        Enabled = False
        TabOrder = 4
        object Panel23: TPanel
          Left = 1
          Top = 1
          Width = 168
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
          Left = 321
          Top = 1
          Width = 128
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
        object pl_ckb2_1: TPanel
          Tag = 1
          Left = 169
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Caption = 'V'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = pl_ckb1_1Click
        end
        object pl_ckb2_2: TPanel
          Tag = 2
          Left = 289
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
          TabOrder = 3
          OnClick = pl_ckb1_1Click
        end
        object edt_max2: TEdit
          Tag = 9
          Left = 481
          Top = 1
          Width = 128
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
          TabOrder = 4
          Text = '9.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel21: TPanel
          Tag = 1
          Left = 449
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
          TabOrder = 5
        end
        object edt_Pi2: TEdit
          Tag = 9
          Left = 201
          Top = 1
          Width = 88
          Height = 29
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
          Text = '5'
          ExplicitHeight = 35
        end
        object plPI2: TPanel
          Tag = 2
          Left = 257
          Top = 6
          Width = 26
          Height = 23
          BevelOuter = bvNone
          Caption = '%'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
      end
      object pl_set_1: TPanel
        Left = 1
        Top = 91
        Width = 611
        Height = 31
        Align = alTop
        Enabled = False
        TabOrder = 5
        object Panel28: TPanel
          Left = 1
          Top = 1
          Width = 168
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
          Left = 321
          Top = 1
          Width = 128
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
        object pl_ckb1_1: TPanel
          Tag = 1
          Left = 169
          Top = 1
          Width = 32
          Height = 29
          Align = alLeft
          Caption = 'V'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'AR DELANEY'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnClick = pl_ckb1_1Click
        end
        object pl_ckb1_2: TPanel
          Tag = 2
          Left = 289
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
          TabOrder = 3
          OnClick = pl_ckb1_1Click
        end
        object edt_max1: TEdit
          Tag = 5
          Left = 481
          Top = 1
          Width = 128
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
          TabOrder = 4
          Text = '5.00'
          OnChange = edt_min1Change
          OnExit = edt_min1Exit
          ExplicitHeight = 35
        end
        object Panel16: TPanel
          Tag = 1
          Left = 449
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
          TabOrder = 5
        end
        object edt_Pi1: TEdit
          Tag = 5
          Left = 201
          Top = 1
          Width = 88
          Height = 29
          Align = alLeft
          Alignment = taCenter
          BevelOuter = bvNone
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ImeMode = imSAlpha
          ParentFont = False
          TabOrder = 6
          Text = '5'
          OnChange = edt_Pi1Change
          OnExit = edt_Pi1Exit
          ExplicitHeight = 35
        end
        object plPI1: TPanel
          Tag = 2
          Left = 257
          Top = 6
          Width = 26
          Height = 23
          BevelOuter = bvNone
          Caption = '%'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -24
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
      end
      object Panel63: TPanel
        Left = 1
        Top = 60
        Width = 611
        Height = 31
        Align = alTop
        Color = clTeal
        ParentBackground = False
        TabOrder = 6
        object Panel64: TPanel
          Left = 1
          Top = 1
          Width = 168
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
        object Panel65: TPanel
          Left = 321
          Top = 1
          Width = 128
          Height = 29
          Align = alLeft
          Caption = #26368#23567#38651#22739'(V)'
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
        object Panel66: TPanel
          Left = 201
          Top = 1
          Width = 88
          Height = 29
          Align = alLeft
          Caption = #35492#24046#30334#20998#27604
          Color = clTeal
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #27161#26999#39636
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
        object Panel14: TPanel
          Left = 481
          Top = 1
          Width = 128
          Height = 29
          Align = alLeft
          Caption = #26368#22823#38651#22739'(V)'
          Color = clTeal
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -20
          Font.Name = #27161#26999#39636
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
        end
        object Panel8: TPanel
          Left = 169
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
        object Panel15: TPanel
          Left = 289
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
          TabOrder = 5
        end
        object Panel17: TPanel
          Left = 449
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
      object pl_Auto: TPanel
        Left = 1
        Top = 33
        Width = 611
        Height = 27
        Align = alTop
        Color = clWhite
        ParentBackground = False
        TabOrder = 7
        object ckbAuto: TCheckBox
          Left = 1
          Top = 1
          Width = 200
          Height = 25
          Hint = #20597#28204#21040#24453#28204#29289'(VPID'#21516#21491#37002#35373#23450')'#25554#20837#26178' '#33258#21205#28204#35430#65292#36895#24230#20381#38651#33126#25928#33021#32780#23450#12290
          Align = alLeft
          BiDiMode = bdLeftToRight
          Caption = 'DUT Plugin Auto Test'
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
          OnClick = ckbAutoClick
        end
        object pl_DutVPID: TPanel
          Left = 201
          Top = 1
          Width = 408
          Height = 25
          Align = alLeft
          Color = clWhite
          ParentBackground = False
          TabOrder = 1
          Visible = False
          object Panel9: TPanel
            Left = 203
            Top = 1
            Width = 204
            Height = 23
            Align = alRight
            TabOrder = 1
            object Panel12: TPanel
              Left = 1
              Top = 1
              Width = 66
              Height = 21
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
            object edtPID: TEdit
              Left = 67
              Top = 1
              Width = 136
              Height = 21
              Align = alClient
              Alignment = taCenter
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              ImeMode = imSAlpha
              ParentFont = False
              TabOrder = 1
              Text = '0000'
              OnChange = edtVIDChange
              ExplicitHeight = 24
            end
          end
          object Panel10: TPanel
            Left = 1
            Top = 1
            Width = 204
            Height = 23
            Align = alLeft
            TabOrder = 0
            object Panel11: TPanel
              Left = 1
              Top = 1
              Width = 64
              Height = 21
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
              TabOrder = 0
            end
            object edtVID: TEdit
              Left = 65
              Top = 1
              Width = 138
              Height = 21
              Align = alClient
              Alignment = taCenter
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              ImeMode = imSAlpha
              ParentFont = False
              TabOrder = 1
              Text = '0000'
              OnChange = edtVIDChange
              ExplicitHeight = 24
            end
          end
        end
      end
    end
  end
  object pl_Memo_Switch: TPanel
    Left = 615
    Top = 0
    Width = 10
    Height = 460
    Align = alRight
    Caption = '>'
    Color = clSkyBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 1
    OnClick = pl_Memo_SwitchClick
  end
  object moDebug: TMemo
    Left = 625
    Top = 0
    Width = 0
    Height = 460
    Align = alRight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 2
    OnChange = moDebugChange
  end
end
