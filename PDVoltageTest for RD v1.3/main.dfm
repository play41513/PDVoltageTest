object FrmMain: TFrmMain
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  ClientHeight = 229
  ClientWidth = 647
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
  object moDebug: TMemo
    Left = 0
    Top = 173
    Width = 647
    Height = 0
    Align = alBottom
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
  object pl_Memo_Switch: TPanel
    Left = 0
    Top = 219
    Width = 647
    Height = 10
    Align = alBottom
    Caption = '^'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 2
    OnMouseDown = pl_Memo_SwitchMouseDown
    OnMouseMove = pl_Memo_SwitchMouseMove
    OnMouseUp = pl_Memo_SwitchMouseUp
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 647
    Height = 173
    Align = alClient
    TabOrder = 0
    object Panel2: TPanel
      Left = 1
      Top = 1
      Width = 129
      Height = 171
      Align = alLeft
      ParentBackground = False
      TabOrder = 0
      object lbRange1: TLabel
        Tag = 5
        Left = 20
        Top = 96
        Width = 3
        Height = 15
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = False
      end
      object pl_read_5v_voltage: TPanel
        Left = 1
        Top = 125
        Width = 127
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
        Width = 127
        Height = 18
        Align = alTop
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'AR DELANEY'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = pl_Auto5VClick
      end
      object plSet5V: TPanel
        Tag = 5
        Left = 1
        Top = 19
        Width = 127
        Height = 106
        Hint = '0'
        Align = alClient
        Caption = '5V'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -33
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = plSet5VClick
      end
    end
    object Panel3: TPanel
      Left = 130
      Top = 1
      Width = 129
      Height = 171
      Align = alLeft
      TabOrder = 1
      object lbRange2: TLabel
        Tag = 9
        Left = 8
        Top = 96
        Width = 3
        Height = 15
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object pl_read_9v_voltage: TPanel
        Left = 1
        Top = 125
        Width = 127
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
        Width = 127
        Height = 18
        Align = alTop
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'AR DELANEY'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = pl_Auto5VClick
      end
      object plSet9V: TPanel
        Tag = 9
        Left = 1
        Top = 19
        Width = 127
        Height = 106
        Hint = '1'
        Align = alClient
        Caption = '9V'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -33
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = plSet5VClick
      end
    end
    object Panel4: TPanel
      Left = 259
      Top = 1
      Width = 129
      Height = 171
      Align = alLeft
      TabOrder = 2
      object lbRange3: TLabel
        Tag = 12
        Left = 8
        Top = 96
        Width = 3
        Height = 15
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object pl_read_12v_voltage: TPanel
        Left = 1
        Top = 125
        Width = 127
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
        Width = 127
        Height = 18
        Align = alTop
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'AR DELANEY'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = pl_Auto5VClick
      end
      object plSet12V: TPanel
        Tag = 12
        Left = 1
        Top = 19
        Width = 127
        Height = 106
        Hint = '2'
        Align = alClient
        Caption = '12V'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -33
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = plSet5VClick
      end
    end
    object Panel5: TPanel
      Left = 388
      Top = 1
      Width = 129
      Height = 171
      Align = alLeft
      TabOrder = 3
      object lbRange4: TLabel
        Tag = 15
        Left = 8
        Top = 96
        Width = 3
        Height = 15
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object pl_read_15v_voltage: TPanel
        Left = 1
        Top = 125
        Width = 127
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
        Width = 127
        Height = 18
        Align = alTop
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'AR DELANEY'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = pl_Auto5VClick
      end
      object plSet15V: TPanel
        Tag = 15
        Left = 1
        Top = 19
        Width = 127
        Height = 106
        Hint = '3'
        Align = alClient
        Caption = '15V'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -33
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = plSet5VClick
      end
    end
    object Panel6: TPanel
      Left = 517
      Top = 1
      Width = 129
      Height = 171
      Align = alLeft
      TabOrder = 4
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
      object pl_read_20v_voltage: TPanel
        Left = 1
        Top = 125
        Width = 127
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
        Width = 127
        Height = 18
        Align = alTop
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'AR DELANEY'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = pl_Auto5VClick
      end
      object plSet20V: TPanel
        Tag = 20
        Left = 1
        Top = 19
        Width = 127
        Height = 106
        Hint = '4'
        Align = alClient
        Caption = '20V'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -33
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = plSet5VClick
      end
    end
  end
  object Panel7: TPanel
    Left = 0
    Top = 173
    Width = 647
    Height = 46
    Align = alBottom
    TabOrder = 3
    object btnStart: TBitBtn
      Left = 330
      Top = 1
      Width = 316
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
    object pl_Auto: TPanel
      Left = 1
      Top = 1
      Width = 144
      Height = 44
      Align = alLeft
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      Visible = False
      object ckbAuto: TCheckBox
        Left = 1
        Top = 1
        Width = 144
        Height = 42
        Align = alLeft
        Caption = 'DUT Plugin Auto Test'
        Color = clCream
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        TabOrder = 0
        OnClick = ckbAutoClick
      end
    end
    object pl_DutVPID: TPanel
      Left = 145
      Top = 1
      Width = 185
      Height = 44
      Align = alLeft
      Color = clWhite
      ParentBackground = False
      TabOrder = 2
      Visible = False
      object Panel9: TPanel
        Left = 1
        Top = 21
        Width = 183
        Height = 22
        Align = alBottom
        TabOrder = 1
        object Panel12: TPanel
          Left = 1
          Top = 1
          Width = 66
          Height = 20
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
          Left = 64
          Top = -1
          Width = 121
          Height = 24
          Alignment = taCenter
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
        end
      end
      object Panel10: TPanel
        Left = 1
        Top = 1
        Width = 183
        Height = 22
        Align = alTop
        TabOrder = 0
        object Panel11: TPanel
          Left = 1
          Top = 1
          Width = 64
          Height = 20
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
          Width = 117
          Height = 20
          Align = alClient
          Alignment = taCenter
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
  object Timer1: TTimer
    Enabled = False
    Left = 16
    Top = 16
  end
end
