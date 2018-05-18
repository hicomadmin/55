import QtQuick 2.3

Item {
    id: keyboard;
    anchors.fill: parent;
    property string inputText: "密码：";


    Image {
        id: keyboardBG;
        anchors.fill: parent;
        source: "qrc:/images/set/Set_keybord_bg.png";
    }

    Image {
        id: inputArea;
        width: 305;
        height: 70;
        anchors.left: parent.left;
        anchors.leftMargin: 282+253;
        anchors.top: parent.top;
        anchors.topMargin: 163;
        source: "qrc:/images/set/Set_keybord_input.png";
        BaseText{
            id: inputAreaText;
            width: 280;
            anchors.left: inputArea.left;
            anchors.leftMargin: 10;
            anchors.verticalCenter: parent.verticalCenter;
            text: keyboard.inputText;
            //elide: Text.ElideLeft;
        }
    }

    BaseButton{
        id:deleteBtn;
        width: 110; height: 110;
        anchors.left: inputArea.right;
        anchors.leftMargin: 13;
        anchors.verticalCenter: inputArea.verticalCenter;
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
        Image {
            anchors.centerIn: parent;
            source: "qrc:/images/set/Set_keybord_del.png";
        }
        onClicked: {
            keyboard.onDeleteBtnClicked();
        }
    }

    Grid {
        anchors.left: parent.left;
        anchors.leftMargin: 282+241;
        anchors.top: parent.top;
        anchors.topMargin: 243;
        columns: 4;
        columnSpacing: 0;
        rowSpacing: 0;
        BaseButton{
            id: btn_1;
            btnText: "1";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_1.btnText);
            }
        }
        BaseButton{
            id: btn_2;
            btnText: "2";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_2.btnText);
            }
        }
        BaseButton{
            id: btn_3;
            btnText: "3";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_3.btnText);
            }
        }
        BaseButton{
            id: btn_4;
            btnText: "4";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_4.btnText);
            }
        }
        BaseButton{
            id: btn_5;
            btnText: "5";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_5.btnText);
            }
        }
        BaseButton{
            id: btn_6;
            btnText: "6";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_6.btnText);
            }
        }
        BaseButton{
            id: btn_7;
            btnText: "7";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_7.btnText);
            }
        }
        BaseButton{
            id: btn_8;
            btnText: "8";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_8.btnText);
            }
        }
        BaseButton{
            id: btn_Ok;
            btnText: qsTr("确认");
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_Ok.btnText);
            }
        }
        BaseButton{
            id: btn_9;
            btnText: "9";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_9.btnText);
            }
        }
        BaseButton{
            id: btn_0;
            btnText: "0";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_0.btnText);
            }
        }
        BaseButton{
            id: btn_cancel;
            btnText: qsTr("取消");
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_cancel.btnText);
            }
        }
    }



    function changeInput(ch)
    {
        if(inputText.length < 11) {
            if(ch === "取消"){
                keyboard.visible = false;
                c_qmlInterface.qmlDebug("Keyboard.qml 取消.");
            }else if(ch === "确认"){
                c_qmlInterface.qmlDebug("Keyboard.qml 确认.");
            }else{
                inputText += ch;
            }

        }
    }

    function onDeleteBtnClicked()
    {
        inputText = inputText.slice(0, -1);
        if(inputText.length == 0) {
            c_qmlInterface.qmlDebug("Keyboard.qml inputText.length == 0.");
        }else{
        }
    }


}
