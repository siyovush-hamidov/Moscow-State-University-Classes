object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1055#1072#1085#1077#1083#1100' '#1058#1086#1074#1072#1088#1086#1074
  ClientHeight = 390
  ClientWidth = 1034
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
    Width = 107
    Height = 29
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 43
    Width = 56
    Height = 29
    Caption = #1062#1077#1085#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 323
    Top = 35
    Width = 122
    Height = 29
    Caption = #1048#1079#1084#1077#1088#1077#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 679
    Top = 35
    Width = 128
    Height = 29
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object DBNavigator1: TDBNavigator
    Left = 601
    Top = 72
    Width = 231
    Height = 48
    DataSource = DataSource1
    VisibleButtons = [nbInsert, nbDelete, nbRefresh]
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 121
    Top = 8
    Width = 888
    Height = 21
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 121
    Top = 45
    Width = 145
    Height = 21
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 461
    Top = 45
    Width = 172
    Height = 21
    TabOrder = 3
  end
  object Edit4: TEdit
    Left = 830
    Top = 45
    Width = 97
    Height = 21
    TabOrder = 4
  end
  object Button1: TButton
    Left = 24
    Top = 96
    Width = 169
    Height = 60
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 199
    Top = 96
    Width = 169
    Height = 60
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 374
    Top = 96
    Width = 169
    Height = 60
    Caption = #1059#1076#1072#1083#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button3Click
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 176
    Width = 995
    Height = 193
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
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
        Width = 60
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'DeviceName'
        Width = 250
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Price'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Measure'
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Quantity'
        Width = 100
        Visible = True
      end>
  end
  object Button4: TButton
    Left = 838
    Top = 72
    Width = 155
    Height = 49
    Action = ClientsPageAction
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
  end
  object Button5: TButton
    Left = 838
    Top = 121
    Width = 155
    Height = 49
    Action = SalesPageAction
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
  end
  object DataSource1: TDataSource
    DataSet = Q1
    Left = 667
    Top = 128
  end
  object ADOConnection1: TADOConnection
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
    Left = 731
    Top = 128
  end
  object Q1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * From t_Prod')
    Left = 604
    Top = 128
  end
  object ActionList1: TActionList
    Left = 800
    Top = 128
    object ClientsPageAction: TAction
      Caption = #1050#1083#1080#1077#1085#1090#1099
      ShortCut = 16460
      OnExecute = ClientsPageActionExecute
    end
    object SalesPageAction: TAction
      Caption = #1055#1088#1086#1076#1072#1078#1080
      OnExecute = SalesPageActionExecute
    end
  end
end
