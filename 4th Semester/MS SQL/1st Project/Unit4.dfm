object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 112
  ClientWidth = 603
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object ComboBox1: TComboBox
    Left = 8
    Top = 32
    Width = 225
    Height = 53
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnSelect = ComboBox1Select
    Items.Strings = (
      #1056#1072#1074#1085#1086
      #1053#1077' '#1088#1072#1074#1085#1086
      #1041#1086#1083#1100#1096#1077
      #1041#1086#1083#1100#1096#1077'/'#1056#1072#1074#1085#1086
      #1052#1077#1085#1100#1096#1077
      #1052#1077#1085#1100#1096#1077'/'#1056#1072#1074#1085#1086
      #1052#1077#1078#1076#1091
      #1041#1086#1083#1100#1096#1077' '#1089#1088#1077#1076#1085#1077#1075#1086
      #1052#1077#1085#1100#1096#1077' '#1089#1088#1077#1076#1085#1077#1075#1086
      '10 '#1089#1072#1084#1099#1093' '#1073#1086#1083#1100#1096#1080#1093
      #1057#1086#1088#1090'('#1091#1073#1099#1074')'
      #1057#1086#1088#1090'('#1074#1086#1079#1088')')
  end
  object Edit1: TEdit
    Left = 250
    Top = 32
    Width = 167
    Height = 53
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 431
    Top = 32
    Width = 164
    Height = 53
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Visible = False
  end
end
