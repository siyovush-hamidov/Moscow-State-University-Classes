object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1055#1072#1085#1077#1083#1100' '#1050#1083#1080#1077#1085#1090#1086#1074
  ClientHeight = 410
  ClientWidth = 1008
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 106
    Height = 25
    Caption = #1048#1084#1103' ('#1060#1048#1054')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 56
    Top = 50
    Width = 58
    Height = 32
    Caption = #1040#1076#1088#1077#1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 29
    Top = 88
    Width = 85
    Height = 25
    Caption = #1058#1077#1083#1077#1092#1086#1085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 136
    Top = 8
    Width = 840
    Height = 25
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 136
    Top = 48
    Width = 840
    Height = 25
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 136
    Top = 88
    Width = 840
    Height = 25
    TabOrder = 2
  end
  object Button1: TButton
    Left = 260
    Top = 119
    Width = 150
    Height = 60
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 416
    Top = 119
    Width = 150
    Height = 60
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 572
    Top = 119
    Width = 150
    Height = 60
    Caption = #1059#1076#1072#1083#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button3Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 379
    Width = 1008
    Height = 31
    Panels = <
      item
        Width = 50
      end>
    ParentFont = True
    UseSystemFont = False
  end
  object DBGrid1: TDBGrid
    Left = 16
    Top = 200
    Width = 960
    Height = 173
    DataSource = DataSource1
    TabOrder = 7
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Width = 30
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
        FieldName = 'HomeAddress'
        Width = 200
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PhoneNumber'
        Width = 100
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 745
    Top = 119
    Width = 231
    Height = 59
    DataSource = DataSource1
    VisibleButtons = [nbInsert, nbDelete, nbRefresh]
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 8
  end
  object ADO1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=C:\Us' +
      'ers\siyov\Desktop\BOBO\C++Builder\Project\DB.mdb;Mode=ReadWrite;' +
      'Persist Security Info=False;Jet OLEDB:System database="";Jet OLE' +
      'DB:Registry Path="";Jet OLEDB:Database Password="";Jet OLEDB:Eng' +
      'ine Type=5;Jet OLEDB:Database Locking Mode=1;Jet OLEDB:Global Pa' +
      'rtial Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB:' +
      'New Database Password="";Jet OLEDB:Create System Database=False;' +
      'Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don'#39't Copy Locale on ' +
      'Compact=False;Jet OLEDB:Compact Without Replica Repair=False;Jet' +
      ' OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmReadWrite
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 33
    Top = 136
  end
  object Q1: TADOQuery
    Active = True
    Connection = ADO1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * From t_Clnt')
    Left = 84
    Top = 136
  end
  object DataSource1: TDataSource
    DataSet = Q1
    Left = 139
    Top = 136
  end
end
