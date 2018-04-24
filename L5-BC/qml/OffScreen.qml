/*************************************************
Copyright: Shenzhen Hangsheng Electronics CO.,LTD.
Author:
Date: 2018-03-13
Description: 待机（POWER OFF）界面
**************************************************/
import QtQuick 2.3


Item {
    width:1280
    height:720

    Image{
        id:close_Haval
        source: ""

        MouseArea {
            anchors.fill: parent
        }
    }


    Component.onCompleted: {
    }

    Component.onDestruction: {
    }
}
