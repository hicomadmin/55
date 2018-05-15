import QtQuick 2.3

Item {
    id: keyboard;
    anchors.fill: parent;
    property string inputText: "";
    signal testMcuBack()


    Rectangle {
        id: keyboardBG;
        anchors.fill: parent;
        color: "#000000";
    }


    BaseText{
        width: 500;
        anchors.left: inputArea.left
        anchors.top: parent.top;
        anchors.topMargin: 10;
        wrapMode: Text.WordWrap;
        text: "MCU测试程序：前中空向主机发送字符串数据(单位为十进制),只发送数据部分以‘-’分割,如果数据只有一位则发送对应数据即可:"
    }

    Rectangle {
        id: inputArea;
        width: 415;
        height: 70;
        anchors.left: parent.left;
        anchors.leftMargin: 282+150;
        anchors.top: parent.top;
        anchors.topMargin: 193;
        color: "#3C3C3C";
        BaseText{
            id: inputAreaText;
            width: 400;
            anchors.left: inputArea.left;
            anchors.leftMargin: 5;
            anchors.verticalCenter: parent.verticalCenter;
            text: keyboard.inputText;
            elide: Text.ElideLeft;
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
        BaseText {
            anchors.centerIn: parent;
            size: 46;
            text: "X"
        }
        onClicked: {
            keyboard.onDeleteBtnClicked();
        }
        onPressAndHold: {
            keyboard.onDeleteBtnHold();
        }

    }

    Grid {
        anchors.left: parent.left;
        anchors.leftMargin: 282+141;
        anchors.top: parent.top;
        anchors.topMargin: 273;
        columns: 5;
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
            id: btn_;
            btnText: "-";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
            pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
            onClicked: {
                keyboard.changeInput(btn_.btnText);
            }
        }
        BaseButton{
            btnText: "";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"";
            pressSource: "";
        }
        BaseButton{
            btnText: "";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"";
            pressSource: "";
        }
        BaseButton{
            btnText: "";
            textsize: 40;
            width: 110; height: 110;
            normalSource:"";
            pressSource: "";
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

    }


    BaseButton{
        id: btn_cancel;
        btnText: qsTr("返回");
        width: 110; height: 110;
        anchors.right: parent.right;
        anchors.rightMargin: 20;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 20;
        normalSource:"qrc:/images/mirror/AC_Tem_nml.png";
        pressSource: "qrc:/images/mirror/AC_Tem_exe.png";
        onClicked: {
            keyboard.changeInput(btn_cancel.btnText);
        }
    }

    function changeInput(ch)
    {
        if(inputText.length < 100) {
            if(ch === "返回"){
                testMcuBack();
            }else if(ch === "确认"){
                console.log("Keyboard.qml 确认. strData = ",inputText);
                c_qmlInterface.sendFccCAN(inputText);
                inputText = "";
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

    function onDeleteBtnHold()
    {
        inputText = "";
    }


}
