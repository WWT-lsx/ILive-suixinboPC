#ifndef stdafx_h_
#define stdafx_h_

#include <QtWidgets>
#include <QtCore/QSettings>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>

#include <set>
#include <time.h>
#include <Windows.h>

#include "iLive.h"
using namespace ilive;
#pragma comment(lib, "iLiveSDK.lib")

#include "Util.h"
#include "PicDownHelper.h"
#include "SxbServerHelper.h"
#include "MainWindow.h"

#ifdef _DEBUG
	#pragma comment(lib, "Qt5Networkd.lib")
#else
	#pragma comment(lib, "Qt5Network.lib")
#endif//_DEBUG

#define SuixinboServerUrl	"https://sxb.qcloud.com/sxb_dev/index.php"
#define SuixinboAppid		1400027849



#define FromStdStr(str) QString::fromStdString(str)
#define FromBits(str) QString::fromLocal8Bit(str)

#define LiveMaster	"LiveMaster" //主播
#define LiveGuest	"LiveGuest"  //连麦观众
#define Guest		"Guest"		 //观众

extern MainWindow* g_pMainWindow;

/////////////////////////随心播信令Start///////////////////////////////
#define LiveNoti "LiveNotification" //自定义信令标记

#define ILVLIVE_IMCMD_CUSTOM_LOW_LIMIT 0x800
#define ILVLIVE_IMCMD_CUSTOM_UP_LIMIT 0x900

enum E_CustomCmd
{
	AVIMCMD_None,               // 无事件：0

	AVIMCMD_EnterLive,          // 用户加入直播, Group消息 ： 1
	AVIMCMD_ExitLive,           // 用户退出直播, Group消息 ： 2
	AVIMCMD_Praise,             // 点赞消息, Demo中使用Group消息 ： 3
	AVIMCMD_Host_Leave,         // 主播或互动观众离开, Group消息 ： 4
	AVIMCMD_Host_Back,          // 主播或互动观众回来, Group消息 ： 5

	AVIMCMD_Multi = ILVLIVE_IMCMD_CUSTOM_LOW_LIMIT,  // 多人互动消息类型 ： 2048

	AVIMCMD_Multi_Host_Invite,          // 多人主播发送邀请消息, C2C消息 ： 2049
	AVIMCMD_Multi_CancelInteract,       // 已进入互动时，断开互动，Group消息，带断开者的imUsreid参数 ： 2050
	AVIMCMD_Multi_Interact_Join,        // 多人互动方收到AVIMCMD_Multi_Host_Invite多人邀请后，同意，C2C消息 ： 2051
	AVIMCMD_Multi_Interact_Refuse,      // 多人互动方收到AVIMCMD_Multi_Invite多人邀请后，拒绝，C2C消息 ： 2052
};
/////////////////////////随心播信令End///////////////////////////////
//发送C2C指令
//dstUser:指令接受用户
//userAction:用户操作
//actionParam:操作参数
void g_sendC2CCustomCmd( QString dstUser, E_CustomCmd userAction, QString actionParam, iLiveSucCallback suc = NULL, iLiveErrCallback err = NULL, void* data = NULL );

//发送群消息
//userAction：用户操作
//actionParam：操作参数
void g_sendGroupCustomCmd( E_CustomCmd userAction, QString actionParam, iLiveSucCallback suc = NULL, iLiveErrCallback err = NULL, void* data = NULL );

#endif//stdafx_h_