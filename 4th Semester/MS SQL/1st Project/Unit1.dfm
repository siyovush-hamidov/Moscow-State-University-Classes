object Form1: TForm1
  Left = 0
  Top = 0
  Anchors = [akLeft]
  Caption = 'Form1'
  ClientHeight = 529
  ClientWidth = 873
  Color = clBtnFace
  Constraints.MinHeight = 530
  Constraints.MinWidth = 873
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  Scaled = False
  Visible = True
  OnCreate = FormCreate
  OnResize = FormResize
  DesignSize = (
    873
    529)
  TextHeight = 15
  object Label1: TLabel
    AlignWithMargins = True
    Left = 3
    Top = 8
    Width = 150
    Height = 30
    AutoSize = False
    Caption = 'Country'
    Color = clAqua
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 170
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label2: TLabel
    AlignWithMargins = True
    Left = 3
    Top = 44
    Width = 150
    Height = 30
    AutoSize = False
    Caption = 'Capital'
    Color = clAqua
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 170
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label3: TLabel
    AlignWithMargins = True
    Left = 3
    Top = 80
    Width = 150
    Height = 30
    AutoSize = False
    Caption = 'Population'
    Color = clAqua
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 170
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Edit1: TEdit
    AlignWithMargins = True
    Left = 151
    Top = 8
    Width = 175
    Height = 30
    Anchors = [akTop]
    AutoSize = False
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Edit2: TEdit
    AlignWithMargins = True
    Left = 151
    Top = 44
    Width = 175
    Height = 30
    Anchors = [akTop]
    AutoSize = False
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object Edit3: TEdit
    AlignWithMargins = True
    Left = 151
    Top = 80
    Width = 175
    Height = 30
    Anchors = [akTop]
    AutoSize = False
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 513
    Top = 8
    Width = 175
    Height = 30
    Anchors = [akTop]
    Caption = 'Find'
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    WordWrap = True
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 694
    Top = 8
    Width = 175
    Height = 30
    Anchors = [akTop]
    Caption = 'Add'
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    WordWrap = True
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 694
    Top = 44
    Width = 175
    Height = 30
    Anchors = [akTop]
    Caption = 'Delete'
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    WordWrap = True
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 513
    Top = 44
    Width = 175
    Height = 30
    Anchors = [akTop]
    Caption = 'Refresh'
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    WordWrap = True
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 513
    Top = 80
    Width = 175
    Height = 30
    Anchors = [akTop]
    Caption = 'Change'
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    WordWrap = True
    OnClick = Button6Click
  end
  object Edit4: TEdit
    Left = 332
    Top = 8
    Width = 175
    Height = 30
    Alignment = taRightJustify
    Anchors = [akTop]
    AutoSize = False
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
  end
  object Edit5: TEdit
    Left = 331
    Top = 44
    Width = 175
    Height = 30
    Alignment = taRightJustify
    Anchors = [akTop]
    AutoSize = False
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
  end
  object Edit6: TEdit
    Left = 331
    Top = 80
    Width = 175
    Height = 30
    Alignment = taRightJustify
    Anchors = [akTop]
    AutoSize = False
    Constraints.MaxHeight = 150
    Constraints.MaxWidth = 500
    Constraints.MinHeight = 20
    Constraints.MinWidth = 150
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 133
    Width = 873
    Height = 396
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Align = alBottom
    Constraints.MaxHeight = 4000
    Constraints.MaxWidth = 2000
    Constraints.MinHeight = 300
    Constraints.MinWidth = 856
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -20
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Segoe UI'
        Font.Style = []
        Width = 50
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Country'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Segoe UI'
        Font.Style = []
        Width = 299
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Capital'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Segoe UI'
        Font.Style = []
        Width = 300
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Population'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Segoe UI'
        Font.Style = []
        Width = 160
        Visible = True
      end>
  end
  object Button9: TButton
    Left = 45
    Top = 133
    Width = 20
    Height = 34
    Anchors = []
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = Button2Click
  end
  object Button10: TButton
    Left = 339
    Top = 134
    Width = 22
    Height = 34
    Anchors = []
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = Button7Click
  end
  object Button11: TButton
    Left = 640
    Top = 134
    Width = 25
    Height = 35
    Anchors = []
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    OnClick = Button8Click
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=MSUDB;Data Source=SIYOVUSH-PC;Use Proce' +
      'dure for Prepare=1;Auto Translate=True;Packet Size=4096;Workstat' +
      'ion ID=SIYOVUSH-PC;Use Encryption for Data=False;Tag with column' +
      ' collation when possible=False'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 716
    Top = 84
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 764
    Top = 84
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from First_Project where ID = ID')
    Left = 812
    Top = 84
  end
end
