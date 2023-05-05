object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 358
  ClientWidth = 951
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 951
    Height = 339
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 339
    Width = 951
    Height = 19
    Panels = <
      item
        Width = 150
      end
      item
        Width = 150
      end
      item
        Width = 150
      end>
  end
  object MainMenu1: TMainMenu
    Left = 408
    Top = 312
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Action = New
      end
      object N3: TMenuItem
        Action = Save
      end
      object N4: TMenuItem
        Action = Close
      end
      object N7: TMenuItem
        Action = Open
      end
    end
    object N5: TMenuItem
      Caption = #1060#1086#1088#1084#1072#1090
      object N6: TMenuItem
        Action = Font
      end
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnIdle = ApplicationEvents1Idle
    Left = 488
    Top = 312
  end
  object ActionList1: TActionList
    Left = 552
    Top = 304
    object Open: TAction
      Caption = #1054#1090#1082#1088#1099#1090#1100
      OnExecute = OpenExecute
    end
    object Save: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      OnExecute = SaveExecute
    end
    object Close: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
    end
    object Font: TAction
      Caption = #1064#1088#1080#1092#1090
      OnExecute = FontExecute
    end
    object New: TAction
      Caption = #1053#1086#1074#1099#1081
      OnExecute = NewExecute
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 328
    Top = 304
  end
  object SaveDialog1: TSaveDialog
    Left = 256
    Top = 296
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Left = 624
    Top = 304
  end
end
