object Form3: TForm3
  Left = 0
  Top = 0
  Caption = #1055#1072#1085#1077#1083#1100' '#1055#1088#1086#1076#1072#1078
  ClientHeight = 412
  ClientWidth = 1008
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 19
    Top = 18
    Width = 42
    Height = 23
    Caption = #1044#1072#1090#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 19
    Top = 59
    Width = 63
    Height = 23
    Caption = #1050#1083#1080#1077#1085#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 19
    Top = 99
    Width = 52
    Height = 23
    Caption = #1058#1086#1074#1072#1088
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 16
    Top = 144
    Width = 101
    Height = 23
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 296
    Top = 144
    Width = 54
    Height = 23
    Caption = #1057#1091#1084#1084#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 544
    Top = 47
    Width = 116
    Height = 23
    Caption = #1054#1073#1097#1072#1103' '#1089#1091#1084#1084#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 544
    Top = 87
    Width = 52
    Height = 23
    Caption = #1043#1086#1088#1086#1076
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object DateTimePicker1: TDateTimePicker
    Left = 96
    Top = 8
    Width = 161
    Height = 33
    Date = 44717.344228865700000000
    Time = 44717.344228865700000000
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 368
    Top = 144
    Width = 137
    Height = 21
    ReadOnly = True
    TabOrder = 1
  end
  object CheckBox1: TCheckBox
    Left = 544
    Top = 8
    Width = 113
    Height = 33
    Caption = #1044#1086#1089#1090#1072#1074#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = CheckBox1Click
  end
  object RadioButton1: TRadioButton
    Left = 680
    Top = 9
    Width = 105
    Height = 32
    Caption = #1054#1073#1099#1095#1085#1072#1103
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 800
    Top = 8
    Width = 129
    Height = 33
    Caption = #1069#1082#1089#1087#1088#1077#1089#1089
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = RadioButton2Click
  end
  object Edit2: TEdit
    Left = 680
    Top = 47
    Width = 193
    Height = 21
    ReadOnly = True
    TabOrder = 5
  end
  object ComboBox4: TComboBox
    Left = 616
    Top = 92
    Width = 297
    Height = 21
    Sorted = True
    TabOrder = 6
  end
  object Button4: TButton
    Left = 616
    Top = 119
    Width = 297
    Height = 67
    Caption = #1044#1054#1041#1040#1042#1048#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button4Click
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 192
    Width = 969
    Height = 201
    DataSource = DataSource1
    TabOrder = 8
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Width = 20
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SaleDate'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ClientName'
        Width = 200
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'DeviceName'
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Quantity'
        Width = 65
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Overall'
        Width = 50
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Delivery'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'TotalSum'
        Width = 50
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'City'
        Visible = True
      end>
  end
  object ComboBox1: TComboBox
    Left = 88
    Top = 64
    Width = 344
    Height = 21
    TabOrder = 9
  end
  object ComboBox2: TComboBox
    Left = 88
    Top = 104
    Width = 344
    Height = 21
    TabOrder = 10
    OnSelect = ComboBox2Select
  end
  object ComboBox3: TComboBox
    Left = 123
    Top = 144
    Width = 129
    Height = 21
    TabOrder = 11
    OnSelect = ComboBox3Select
  end
  object DataSource1: TDataSource
    DataSet = Q1
    Left = 408
    Top = 8
  end
  object Timer1: TTimer
    Left = 472
    Top = 8
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\siyov\Desk' +
      'top\BOBO\C++Builder\Project\DB.mdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 360
    Top = 8
  end
  object Q1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * From t_Sell')
    Left = 312
    Top = 8
  end
  object Q2: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * From t_Clnt')
    Left = 536
    Top = 128
  end
  object DataSource2: TDataSource
    DataSet = Q2
    Left = 576
    Top = 128
  end
  object Q3: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * From t_Prod'
      '')
    Left = 632
    Top = 128
  end
  object DataSource3: TDataSource
    DataSet = Q3
    Left = 664
    Top = 128
  end
  object DataSource4: TDataSource
    DataSet = Q4
    Left = 752
    Top = 128
  end
  object Q4: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * From t_Prod'
      '')
    Left = 712
    Top = 128
  end
  object Q5: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * From t_Sell')
    Left = 848
    Top = 296
  end
  object DataSource5: TDataSource
    DataSet = Q5
    Left = 888
    Top = 296
  end
end
