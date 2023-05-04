object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 451
  ClientWidth = 756
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 49
    Width = 215
    Height = 385
    TabOrder = 0
    Visible = False
    object DirectoryListBox1: TDirectoryListBox
      Left = 5
      Top = 35
      Width = 125
      Height = 342
      FileList = FileListBox1
      TabOrder = 0
    end
    object DriveComboBox1: TDriveComboBox
      Left = 7
      Top = 8
      Width = 202
      Height = 21
      DirList = DirectoryListBox1
      TabOrder = 1
    end
    object FileListBox1: TFileListBox
      Left = 135
      Top = 35
      Width = 75
      Height = 342
      ItemHeight = 15
      Mask = '*.db*'
      MultiSelect = True
      TabOrder = 2
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 48
    Width = 215
    Height = 385
    TabOrder = 1
    Visible = False
    OnClick = RadioButton1Click
    object ListBox1: TListBox
      Left = 5
      Top = 8
      Width = 100
      Height = 369
      ItemHeight = 15
      TabOrder = 0
    end
    object ListBox2: TListBox
      Left = 110
      Top = 8
      Width = 100
      Height = 369
      ItemHeight = 15
      TabOrder = 1
    end
  end
  object RadioButton1: TRadioButton
    Left = 6
    Top = 8
    Width = 97
    Height = 27
    Caption = '*.db'
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 2
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 111
    Top = 8
    Width = 97
    Height = 27
    Caption = '*.mdf'
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 3
    OnClick = RadioButton1Click
  end
  object Memo1: TMemo
    Left = 221
    Top = 57
    Width = 530
    Height = 184
    TabOrder = 4
  end
  object Panel3: TPanel
    Left = 221
    Top = 7
    Width = 527
    Height = 35
    TabOrder = 5
  end
  object Memo2: TMemo
    Left = 221
    Top = 256
    Width = 530
    Height = 170
    TabOrder = 6
  end
  object DBGrid1: TDBGrid
    Left = 221
    Top = 256
    Width = 530
    Height = 170
    TabOrder = 7
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Visible = False
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=master;Data Source=SIYOVUSH-LT'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 592
    Top = 384
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from sysdatabases where dbid > 4')
    Left = 648
    Top = 384
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 704
    Top = 384
  end
end
