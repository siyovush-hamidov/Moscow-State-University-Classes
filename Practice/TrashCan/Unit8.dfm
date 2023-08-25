object StaffWindow: TStaffWindow
  Left = 0
  Top = 0
  Caption = 'StaffWindow'
  ClientHeight = 702
  ClientWidth = 1108
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWhite
  Font.Height = -19
  Font.Name = 'Oswald Light'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 32
  object VirtualImage1: TVirtualImage
    Left = -9
    Top = -380
    Width = 335
    Height = 1229
    ImageCollection = MainWindow.ImageCollection1
    ImageWidth = 0
    ImageHeight = 0
    ImageIndex = 2
    ImageName = 'BlueBackground'
    Proportional = False
  end
  object VirtualImage4: TVirtualImage
    Left = 0
    Top = 35
    Width = 326
    Height = 58
    Cursor = crHandPoint
    ImageCollection = MainWindow.ImageCollection1
    ImageWidth = 0
    ImageHeight = 0
    ImageIndex = 2
    ImageName = 'BlueBackground'
    Proportional = False
    OnMouseEnter = Label13MouseEnter
    OnMouseLeave = Label13MouseLeave
  end
  object VirtualImage12: TVirtualImage
    Left = 37
    Top = 26
    Width = 252
    Height = 2
    ImageCollection = MainWindow.ImageCollection1
    ImageWidth = 0
    ImageHeight = 0
    ImageIndex = 10
    ImageName = 'WhiteBackground'
    Proportional = False
  end
  object VirtualImage5: TVirtualImage
    Left = 37
    Top = 99
    Width = 252
    Height = 2
    ImageCollection = MainWindow.ImageCollection1
    ImageWidth = 0
    ImageHeight = 0
    ImageIndex = 10
    ImageName = 'WhiteBackground'
    Proportional = False
  end
  object Label13: TLabel
    Left = 87
    Top = 43
    Width = 159
    Height = 36
    Cursor = crHandPoint
    Caption = #1044#1054#1041#1040#1042#1048#1058#1068' '#1047#1040#1053#1071#1058#1048#1045
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWhite
    Font.Height = -21
    Font.Name = 'Oswald Light'
    Font.Style = []
    ParentFont = False
    Transparent = True
    OnClick = Label13Click
    OnMouseEnter = Label13MouseEnter
    OnMouseLeave = Label13MouseLeave
  end
  object VirtualImage3: TVirtualImage
    Left = 0
    Top = 107
    Width = 326
    Height = 58
    Cursor = crHandPoint
    ImageCollection = MainWindow.ImageCollection1
    ImageWidth = 0
    ImageHeight = 0
    ImageIndex = 2
    ImageName = 'BlueBackground'
    Proportional = False
    OnMouseEnter = Label13MouseEnter
    OnMouseLeave = Label13MouseLeave
  end
  object Label1: TLabel
    Left = 44
    Top = 116
    Width = 239
    Height = 36
    Cursor = crHandPoint
    Caption = #1056#1045#1044#1040#1050#1058#1048#1056#1054#1042#1040#1058#1068' '#1056#1040#1057#1055#1048#1057#1040#1053#1048#1045
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWhite
    Font.Height = -21
    Font.Name = 'Oswald Light'
    Font.Style = []
    ParentFont = False
    Transparent = True
    OnClick = Label1Click
    OnMouseEnter = Label13MouseEnter
    OnMouseLeave = Label13MouseLeave
  end
  object VirtualImage6: TVirtualImage
    Left = 37
    Top = 171
    Width = 252
    Height = 2
    ImageCollection = MainWindow.ImageCollection1
    ImageWidth = 0
    ImageHeight = 0
    ImageIndex = 10
    ImageName = 'WhiteBackground'
    Proportional = False
  end
  object LessonConstructor: TPanel
    Left = 325
    Top = -8
    Width = 789
    Height = 740
    TabOrder = 0
    Visible = False
    object Label4: TLabel
      Left = 41
      Top = 39
      Width = 26
      Height = 27
      Caption = #1044#1072#1090#1072
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 41
      Top = 102
      Width = 28
      Height = 27
      Caption = #1055#1072#1088#1072
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 41
      Top = 164
      Width = 57
      Height = 27
      Caption = #1060#1072#1082#1091#1083#1100#1090#1077#1090
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 41
      Top = 227
      Width = 74
      Height = 27
      Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 41
      Top = 291
      Width = 27
      Height = 27
      Caption = #1050#1091#1088#1089
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 41
      Top = 352
      Width = 60
      Height = 27
      Caption = #1040#1091#1076#1080#1090#1086#1088#1080#1103
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 41
      Top = 411
      Width = 85
      Height = 27
      Caption = #1055#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1100
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label11: TLabel
      Left = 41
      Top = 474
      Width = 70
      Height = 27
      Caption = #1044#1080#1089#1094#1080#1087#1083#1080#1085#1072
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 41
      Top = 538
      Width = 67
      Height = 27
      Caption = #1058#1080#1087' '#1079#1072#1085#1103#1090#1080#1103
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Button1: TButton
      Left = 406
      Top = 625
      Width = 220
      Height = 51
      Cursor = crHandPoint
      Caption = #1054#1063#1048#1057#1058#1048#1058#1068
      TabOrder = 0
      StyleName = 'Tablet Dark'
      OnClick = Button1Click
    end
    object ComboBox7: TComboBox
      Left = 41
      Top = 499
      Width = 701
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnDropDown = ComboBox7DropDown
    end
    object DateTimePicker1: TDateTimePicker
      Left = 41
      Top = 64
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Hint = #1044#1072#1090#1072
      Date = 45140.000000000000000000
      Time = 0.752999374999490100
      TabOrder = 2
      OnChange = DateTimePicker1Change
    end
    object ComboBox1: TComboBox
      Left = 41
      Top = 189
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnDropDown = ComboBox1DropDown
      OnSelect = ComboBox1Select
    end
    object ComboBox2: TComboBox
      Left = 41
      Top = 252
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Enabled = False
      ExtendedUI = True
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnDropDown = ComboBox2DropDown
    end
    object ComboBox3: TComboBox
      Left = 41
      Top = 316
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnDropDown = ComboBox3DropDown
      Items.Strings = (
        ''
        ''
        ''
        '')
    end
    object ComboBox4: TComboBox
      Left = 41
      Top = 127
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      ExtendedUI = True
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 6
      Items.Strings = (
        '1-'#1103' '#1087#1072#1088#1072
        '2-'#1103' '#1087#1072#1088#1072
        '3-'#1103' '#1087#1072#1088#1072
        '4-'#1103' '#1087#1072#1088#1072)
    end
    object ComboBox5: TComboBox
      Left = 41
      Top = 377
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnDropDown = ComboBox5DropDown
    end
    object ComboBox6: TComboBox
      Left = 41
      Top = 436
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      Sorted = True
      TabOrder = 8
      OnDropDown = ComboBox6DropDown
      OnSelect = ComboBox6Select
    end
    object ComboBox8: TComboBox
      Left = 41
      Top = 563
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      Items.Strings = (
        #1051#1077#1082#1094#1080#1086#1085#1085#1086#1077' '#1079#1072#1085#1103#1090#1080#1077
        #1055#1088#1072#1082#1090#1080#1095#1077#1089#1082#1086#1077' '#1079#1072#1085#1103#1090#1080#1077
        #1047#1072#1095#1105#1090
        #1069#1082#1079#1072#1084#1077#1085
        #1050#1086#1085#1089#1091#1083#1100#1090#1072#1094#1080#1103)
    end
    object Button3: TButton
      Left = 163
      Top = 625
      Width = 220
      Height = 51
      Cursor = crHandPoint
      Caption = #1044#1054#1041#1040#1042#1048#1058#1068
      TabOrder = 10
      StyleName = 'Tablet Dark'
      OnClick = Button3Click
    end
  end
  object LessonEditor: TPanel
    Left = 325
    Top = -8
    Width = 788
    Height = 740
    TabOrder = 1
    Visible = False
    object Label3: TLabel
      Left = 41
      Top = 22
      Width = 26
      Height = 27
      Caption = #1044#1072#1090#1072
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 41
      Top = 85
      Width = 28
      Height = 27
      Caption = #1055#1072#1088#1072
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label15: TLabel
      Left = 41
      Top = 147
      Width = 57
      Height = 27
      Caption = #1060#1072#1082#1091#1083#1100#1090#1077#1090
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label16: TLabel
      Left = 41
      Top = 210
      Width = 74
      Height = 27
      Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label17: TLabel
      Left = 41
      Top = 272
      Width = 27
      Height = 27
      Caption = #1050#1091#1088#1089
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label18: TLabel
      Left = 396
      Top = 362
      Width = 60
      Height = 27
      Caption = #1040#1091#1076#1080#1090#1086#1088#1080#1103
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label19: TLabel
      Left = 396
      Top = 428
      Width = 85
      Height = 27
      Caption = #1055#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1100
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label20: TLabel
      Left = 396
      Top = 490
      Width = 70
      Height = 27
      Caption = #1044#1080#1089#1094#1080#1087#1083#1080#1085#1072
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label21: TLabel
      Left = 396
      Top = 553
      Width = 67
      Height = 27
      Caption = #1058#1080#1087' '#1079#1072#1085#1103#1090#1080#1103
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object VirtualImage2: TVirtualImage
      Left = 41
      Top = 361
      Width = 700
      Height = 2
      ImageCollection = MainWindow.ImageCollection1
      ImageWidth = 0
      ImageHeight = 0
      ImageIndex = 2
      ImageName = 'BlueBackground'
      Proportional = False
    end
    object Label2: TLabel
      Left = 43
      Top = 362
      Width = 26
      Height = 27
      Caption = #1044#1072#1090#1072
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label22: TLabel
      Left = 41
      Top = 428
      Width = 28
      Height = 27
      Caption = #1055#1072#1088#1072
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label23: TLabel
      Left = 41
      Top = 490
      Width = 57
      Height = 27
      Caption = #1060#1072#1082#1091#1083#1100#1090#1077#1090
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label24: TLabel
      Left = 41
      Top = 553
      Width = 74
      Height = 27
      Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Label25: TLabel
      Left = 41
      Top = 615
      Width = 27
      Height = 27
      Caption = #1050#1091#1088#1089
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
    end
    object Button2: TButton
      Left = 576
      Top = 642
      Width = 165
      Height = 40
      Cursor = crHandPoint
      Caption = #1054#1063#1048#1057#1058#1048#1058#1068
      Enabled = False
      TabOrder = 0
      StyleName = 'Windows'
      OnClick = Button2Click
    end
    object ComboBox17: TComboBox
      Left = 396
      Top = 515
      Width = 345
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnDropDown = ComboBox17DropDown
    end
    object DateTimePicker2: TDateTimePicker
      Left = 41
      Top = 47
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Hint = #1044#1072#1090#1072
      Date = 45155.000000000000000000
      Time = 0.752999374999490100
      TabOrder = 2
      OnChange = ComboBox13Select
    end
    object ComboBox10: TComboBox
      Left = 41
      Top = 172
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnDropDown = ComboBox10DropDown
      OnSelect = ComboBox10Select
    end
    object ComboBox11: TComboBox
      Left = 41
      Top = 235
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Enabled = False
      ExtendedUI = True
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnDropDown = ComboBox11DropDown
      OnSelect = ComboBox13Select
    end
    object ComboBox12: TComboBox
      Left = 41
      Top = 299
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnSelect = ComboBox13Select
      Items.Strings = (
        '1-'#1081' '#1082#1091#1088#1089
        '2-'#1081' '#1082#1091#1088#1089
        '3-'#1081' '#1082#1091#1088#1089
        '4-'#1081' '#1082#1091#1088#1089)
    end
    object ComboBox13: TComboBox
      Left = 41
      Top = 110
      Width = 700
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      ExtendedUI = True
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 6
      OnSelect = ComboBox13Select
      Items.Strings = (
        '1-'#1103' '#1087#1072#1088#1072
        '2-'#1103' '#1087#1072#1088#1072
        '3-'#1103' '#1087#1072#1088#1072
        '4-'#1103' '#1087#1072#1088#1072)
    end
    object ComboBox14: TComboBox
      Left = 396
      Top = 390
      Width = 345
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnDropDown = ComboBox14DropDown
    end
    object ComboBox15: TComboBox
      Left = 396
      Top = 453
      Width = 345
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      Sorted = True
      TabOrder = 8
      OnDropDown = ComboBox15DropDown
      OnSelect = ComboBox6Select
    end
    object ComboBox16: TComboBox
      Left = 396
      Top = 578
      Width = 345
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      Items.Strings = (
        #1051#1077#1082#1094#1080#1086#1085#1085#1086#1077' '#1079#1072#1085#1103#1090#1080#1077
        #1055#1088#1072#1082#1090#1080#1095#1077#1089#1082#1086#1077' '#1079#1072#1085#1103#1090#1080#1077
        #1047#1072#1095#1105#1090
        #1069#1082#1079#1072#1084#1077#1085
        #1050#1086#1085#1089#1091#1083#1100#1090#1072#1094#1080#1103)
    end
    object Button4: TButton
      Left = 396
      Top = 642
      Width = 165
      Height = 40
      Cursor = crHandPoint
      Caption = #1042#1053#1045#1057#1058#1048' '#1048#1047#1052#1045#1053#1045#1053#1048#1071
      Enabled = False
      TabOrder = 10
      StyleName = 'Windows'
      OnClick = Button4Click
    end
    object DateTimePicker3: TDateTimePicker
      Left = 41
      Top = 390
      Width = 345
      Height = 40
      Cursor = crHandPoint
      Hint = #1044#1072#1090#1072
      Date = 45155.000000000000000000
      Time = 0.752999374999490100
      Enabled = False
      TabOrder = 11
      StyleName = 'Windows'
    end
    object ComboBox9: TComboBox
      Left = 41
      Top = 453
      Width = 345
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Enabled = False
      ExtendedUI = True
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 12
      Items.Strings = (
        '1-'#1103' '#1087#1072#1088#1072
        '2-'#1103' '#1087#1072#1088#1072
        '3-'#1103' '#1087#1072#1088#1072
        '4-'#1103' '#1087#1072#1088#1072)
    end
    object ComboBox18: TComboBox
      Left = 41
      Top = 515
      Width = 345
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 13
      OnDropDown = ComboBox18DropDown
      OnSelect = ComboBox18Select
    end
    object ComboBox19: TComboBox
      Left = 41
      Top = 578
      Width = 345
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Enabled = False
      ExtendedUI = True
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 14
      OnDropDown = ComboBox19DropDown
    end
    object ComboBox20: TComboBox
      Left = 41
      Top = 642
      Width = 345
      Height = 40
      Cursor = crHandPoint
      Style = csDropDownList
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clMenuText
      Font.Height = -19
      Font.Name = 'Oswald Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 15
      OnDropDown = ComboBox20DropDown
      Items.Strings = (
        '1-'#1081' '#1082#1091#1088#1089
        '2-'#1081' '#1082#1091#1088#1089
        '3-'#1081' '#1082#1091#1088#1089
        '4-'#1081' '#1082#1091#1088#1089)
    end
  end
  object ADOQuery1: TADOQuery
    Connection = MainWindow.ADOConnection1
    Parameters = <>
    Left = 32
    Top = 632
  end
end
