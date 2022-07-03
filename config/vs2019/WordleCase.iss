#define QTDIR "C:\Qt\5.15.1\msvc2019_64"

#define CoinTrader_OutDir "..\vs2019\x64\DLL Release"
#define CoinTrader_Version GetFileVersion('..\vs2019\x64\DLL Release\CoinTrader.exe')

[Setup]
AppName=CoinTrader
AppVersion={#CoinTrader_Version}
DefaultDirName={pf}\CoinTrader\
DefaultGroupName=CoinTrader
UninstallDisplayIcon={app}\uninstall.exe
Compression=lzma2
SolidCompression=yes
OutputDir=userdocs:CoinTrader Setup
OutputBaseFilename=CoinTrader Setup v{#CoinTrader_Version}

[Files]
; Exe Files
Source: "{#CoinTrader_OutDir}\CoinTrader.exe"; DestDir: "{app}";

; Visual C++ Redistributable Package Files
Source: "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Redist\MSVC\14.29.30133\vc_redist.x64.exe"; DestDir: {app}; Flags: deleteafterinstall

; Config Files
Source: "{#CoinTrader_OutDir}\CoinTrader.xml"; DestDir: "{app}"

;Application Libraries
Source: "{#CoinTrader_OutDir}\Application.dll"; DestDir: "{app}"
Source: "{#CoinTrader_OutDir}\CoreApplication.dll"; DestDir: "{app}"
Source: "{#CoinTrader_OutDir}\BinanceClient.dll"; DestDir: "{app}"

;Plugins
Source: "{#CoinTrader_OutDir}\NotificationPlugin.dll"; DestDir: "{app}"
Source: "{#CoinTrader_OutDir}\SamplePlugin.dll"; DestDir: "{app}"
Source: "{#CoinTrader_OutDir}\SpotOverviewPlugin.dll"; DestDir: "{app}"
Source: "{#CoinTrader_OutDir}\TrendFinderPlugin.dll"; DestDir: "{app}"

; Qt DLLs
Source: "{#QTDIR}\bin\Qt5Core.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5Gui.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5Widgets.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5Network.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5Xml.dll"; DestDir: "{app}"
Source: "{#QTDIR}\plugins\platforms\qminimal.dll"; DestDir: "{app}\platforms"
Source: "{#QTDIR}\plugins\platforms\qoffscreen.dll"; DestDir: "{app}\platforms"
Source: "{#QTDIR}\plugins\platforms\qwindows.dll"; DestDir: "{app}\platforms"
Source: "{#QTDIR}\plugins\styles\qwindowsvistastyle.dll"; DestDir: "{app}\styles"

; Data Files
Source: "..\..\data\transactions\*"; DestDir: "{app}\transactions"; Flags: ignoreversion recursesubdirs

; Icon Files
Source: "..\..\src\CoinTrader\CoinTrader.ico"; DestDir: "{app}"
Source: "..\..\data\icons\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs

[Icons]
Name: "{group}\CoinTrader"; Filename: "{app}\CoinTrader.exe"
Name: "{commondesktop}\CoinTrader"; Filename: "{app}\CoinTrader.exe"; Parameters: ""; IconFilename: "{app}\CoinTrader.ico"

[Code]
procedure AfterInstallMessage();
begin
  MsgBox('CoinTrader intallation finished.', mbInformation, MB_OK);
end;

[Run]
Filename: {app}\vc_redist.x64.exe; \
    Parameters: "/passive /verysilent /norestart /q:a /c:""VCREDI~3.EXE /q:a /c:""""msiexec /i vcredist.msi /qn"""" """; \
    StatusMsg: Installing Visual C++ Redistributable Package...
