#define QTDIR "C:\Qt\5.15.2\msvc2019_64"

#define WordleCase_OutDir "..\vs2019\x64\DLL Release"
#define WordleCase_Version GetFileVersion('..\vs2019\x64\DLL Release\WordleCase.exe')

[Setup]
AppName=WordleCase
AppVersion={#WordleCase_Version}
DefaultDirName={pf}\WordleCase\
DefaultGroupName=WordleCase
UninstallDisplayIcon={app}\uninstall.exe
Compression=lzma2
SolidCompression=yes
OutputDir=userdocs:WordleCase Setup
OutputBaseFilename=WordleCase Setup v{#WordleCase_Version}

[Files]
; Exe Files
Source: "{#WordleCase_OutDir}\WordleCase.exe"; DestDir: "{app}";

; Visual C++ Redistributable Package Files
Source: "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Redist\MSVC\14.29.30133\vc_redist.x64.exe"; DestDir: {app}; Flags: deleteafterinstall

; Config Files
Source: "{#WordleCase_OutDir}\WordleCase.xml"; DestDir: "{app}"

;Application Libraries
Source: "{#WordleCase_OutDir}\CoreApplication.dll"; DestDir: "{app}"
Source: "{#WordleCase_OutDir}\QmlApplication.dll"; DestDir: "{app}"

;Plugins
Source: "{#WordleCase_OutDir}\WordleCheckPlugin.dll"; DestDir: "{app}"

; Qt DLLs
Source: "{#QTDIR}\bin\Qt5Core.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5Gui.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5Network.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5Widgets.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5Xml.dll"; DestDir: "{app}"

Source: "{#QTDIR}\bin\Qt5Qml.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5QmlModels.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5QmlWorkerScript.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5Quick.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5QuickControls2.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5QuickShapes.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5QuickTemplates2.dll"; DestDir: "{app}"
Source: "{#QTDIR}\bin\Qt5QuickWidgets.dll"; DestDir: "{app}"

Source: "{#QTDIR}\plugins\platforms\qminimal.dll"; DestDir: "{app}\platforms"
Source: "{#QTDIR}\plugins\platforms\qoffscreen.dll"; DestDir: "{app}\platforms"
Source: "{#QTDIR}\plugins\platforms\qwindows.dll"; DestDir: "{app}\platforms"
Source: "{#QTDIR}\plugins\styles\qwindowsvistastyle.dll"; DestDir: "{app}\styles"

; Qml Dependencies
Source: "{#QTDIR}\qml\QtQuick.2\*"; Excludes: "*d.dll,*.pdb"; DestDir: "{app}\QtQuick.2"; Flags: recursesubdirs
Source: "{#QTDIR}\qml\QtQuick\*"; Excludes: "*d.dll,*.pdb"; DestDir: "{app}\QtQuick"; Flags: recursesubdirs
Source: "{#QTDIR}\qml\Qt\labs\folderlistmodel\*"; Excludes: "*d.dll,*.pdb"; DestDir: "{app}\Qt\labs\folderlistmodel"; Flags: recursesubdirs
Source: "{#QTDIR}\qml\Qt\labs\settings\*"; Excludes: "*d.dll,*.pdb"; DestDir: "{app}\Qt\labs\settings"; Flags: recursesubdirs
Source: "{#QTDIR}\qml\QtGraphicalEffects\*"; Excludes: "*d.dll,*.pdb"; DestDir: "{app}\QtGraphicalEffects"; Flags: recursesubdirs
Source: "{#QTDIR}\qml\QtMultimedia\*"; Excludes: "*d.dll,*.pdb"; DestDir: "{app}\QtMultimedia"; Flags: recursesubdirs
Source: "{#QTDIR}\qml\QtPositioning\*"; Excludes: "*d.dll,*.pdb"; DestDir: "{app}\QtPositioning"; Flags: recursesubdirs
Source: "{#QTDIR}\qml\QtQml\Models.2\*"; Excludes: "*d.dll,*.pdb"; DestDir: "{app}\QtQml\Models.2"; Flags: recursesubdirs
Source: "{#QTDIR}\qml\Qt3D\*"; Excludes: "*d.dll,*.pdb"; DestDir: "{app}\Qt3D"; Flags: recursesubdirs

; Data Files
Source: "..\..\data\QmlData\*"; DestDir: "{app}\QmlData"; Flags: recursesubdirs

[Icons]
Name: "{commondesktop}\WordleCase"; Filename: "{app}\WordleCase.exe"; Parameters: "";

[Code]
procedure AfterInstallMessage();
begin
  MsgBox('CoinTrader intallation finished.', mbInformation, MB_OK);
end;

[Run]
Filename: {app}\vc_redist.x64.exe; \
    Parameters: "/passive /verysilent /norestart /q:a /c:""VCREDI~3.EXE /q:a /c:""""msiexec /i vcredist.msi /qn"""" """; \
    StatusMsg: Installing Visual C++ Redistributable Package...
