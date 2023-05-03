object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 488
  ClientWidth = 695
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Panel1: TPanel
    Left = -1
    Top = 49
    Width = 321
    Height = 434
    TabOrder = 0
    Visible = False
    object DirectoryListBox1: TDirectoryListBox
      Left = 16
      Top = 35
      Width = 185
      Height = 382
      FileList = FileListBox1
      TabOrder = 0
    end
    object DriveComboBox1: TDriveComboBox
      Left = 16
      Top = 8
      Width = 296
      Height = 21
      DirList = DirectoryListBox1
      TabOrder = 1
    end
    object FileListBox1: TFileListBox
      Left = 207
      Top = 35
      Width = 105
      Height = 382
      ItemHeight = 15
      Mask = '*.db*'
      MultiSelect = True
      TabOrder = 2
    end
  end
  object Panel2: TPanel
    Left = -1
    Top = 49
    Width = 321
    Height = 434
    TabOrder = 1
    Visible = False
    OnClick = RadioButton1Click
    object ListBox1: TListBox
      Left = 7
      Top = 8
      Width = 149
      Height = 409
      ItemHeight = 15
      TabOrder = 0
    end
    object ListBox2: TListBox
      Left = 163
      Top = 8
      Width = 149
      Height = 409
      ItemHeight = 15
      TabOrder = 1
    end
  end
  object RadioButton1: TRadioButton
    Left = 6
    Top = 18
    Width = 97
    Height = 17
    Caption = '*.db'
    Color = clBlack
    ParentColor = False
    TabOrder = 2
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 111
    Top = 18
    Width = 97
    Height = 17
    Caption = '*.mdb'
    Color = clBlack
    ParentColor = False
    TabOrder = 3
    OnClick = RadioButton1Click
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=master;Data Source=SIYOVUSH-PC'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 200
    Top = 8
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sysdatabases WHERE status = 16')
    Left = 256
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 312
    Top = 8
  end
end
