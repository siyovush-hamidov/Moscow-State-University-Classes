object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1056#1072#1073#1086#1090#1072' '#1089' '#1089#1080#1084#1074#1086#1083#1072#1084#1080
  ClientHeight = 376
  ClientWidth = 810
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 432
    Top = 79
    Width = 51
    Height = 23
    Caption = #1047#1085#1072#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 620
    Top = 79
    Width = 53
    Height = 23
    Caption = #1063#1080#1089#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 432
    Top = 150
    Width = 60
    Height = 23
    Caption = 'English'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 622
    Top = 150
    Width = 67
    Height = 23
    Caption = #1056#1091#1089#1089#1082#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 401
    Height = 265
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    PopupMenu = PopupMenu1
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Button2: TButton
    Left = 216
    Top = 279
    Width = 177
    Height = 72
    Cursor = crHandPoint
    Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083
    Caption = #1042#1089#1077' '#1089#1083#1086#1074#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button1: TButton
    Left = 24
    Top = 279
    Width = 186
    Height = 72
    Cursor = crHandPoint
    Caption = 'Open File'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 432
    Top = 221
    Width = 172
    Height = 61
    Cursor = crHandPoint
    Hint = #1057#1084#1077#1085#1080#1090#1100' '#1064#1088#1080#1092#1090
    Caption = #1047#1085#1072#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 620
    Top = 221
    Width = 172
    Height = 61
    Cursor = crHandPoint
    Caption = #1063#1080#1089#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button4Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 357
    Width = 810
    Height = 19
    Panels = <
      item
        Width = 110
      end
      item
        Width = 110
      end
      item
        Width = 110
      end
      item
        Width = 110
      end>
  end
  object Button5: TButton
    Left = 432
    Top = 288
    Width = 172
    Height = 63
    Cursor = crHandPoint
    Caption = #1040#1085#1075#1083#1080#1081#1089#1082#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 620
    Top = 288
    Width = 174
    Height = 63
    Cursor = crHandPoint
    Caption = #1056#1091#1089#1089#1082#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button6Click
  end
  object ListBox1: TListBox
    Left = 430
    Top = 8
    Width = 364
    Height = 65
    ItemHeight = 13
    TabOrder = 8
  end
  object ListBox2: TListBox
    Left = 529
    Top = 79
    Width = 75
    Height = 65
    ItemHeight = 13
    TabOrder = 9
  end
  object ListBox3: TListBox
    Left = 719
    Top = 79
    Width = 75
    Height = 65
    ItemHeight = 13
    TabOrder = 10
  end
  object ListBox4: TListBox
    Left = 719
    Top = 150
    Width = 75
    Height = 65
    ItemHeight = 13
    TabOrder = 11
  end
  object ListBox5: TListBox
    Left = 529
    Top = 150
    Width = 75
    Height = 65
    ItemHeight = 13
    TabOrder = 12
  end
  object MainMenu1: TMainMenu
    Left = 200
    Top = 29
    object N1: TMenuItem
      Caption = '&File'
      object Open1: TMenuItem
        Action = OpenAction
      end
      object Save1: TMenuItem
        Action = SaveAction
      end
    end
    object Edit1: TMenuItem
      Caption = 'Edit'
      object Font1: TMenuItem
        Action = FontAction
      end
      object Clear1: TMenuItem
        Action = ClearAction
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'TXT File|*.txt|All Type Files|*.*'
    Left = 264
    Top = 85
  end
  object SaveDialog1: TSaveDialog
    Filter = 'TXT File|*.txt|All Type Files|*.*'
    Left = 264
    Top = 29
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Left = 344
    Top = 32
  end
  object PopupMenu1: TPopupMenu
    Left = 344
    Top = 88
    object Font2: TMenuItem
      Caption = 'Font'
    end
    object Clear2: TMenuItem
      Caption = 'Clear'
    end
  end
  object ActionList1: TActionList
    Left = 264
    Top = 141
    object OpenAction: TAction
      Caption = 'Open'
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083
    end
    object SaveAction: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083
      OnExecute = Button2Click
    end
    object FontAction: TAction
      Caption = #1064#1088#1080#1092#1090
      Checked = True
      Hint = #1057#1084#1077#1085#1080#1090#1100' '#1064#1088#1080#1092#1090
    end
    object ClearAction: TAction
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    end
    object NewAction: TAction
      Caption = #1053#1086#1074#1099#1081
      OnExecute = Button3Click
    end
    object SearchAction: TAction
      Caption = #1057#1080#1084#1074#1086#1083#1099
    end
    object Action1: TAction
      Caption = 'Action1'
    end
    object Action2: TAction
      Caption = 'Action2'
    end
  end
  object ApplicationEvents1: TApplicationEvents
    Left = 344
    Top = 144
  end
end
