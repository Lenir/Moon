
이 포스팅은 한국어, 영어로 적혀 있습니다. 위 셀렉트 박스에서 언어 설정이 가능합니다. 형편없는 영어 실력 양해 바랍니다.<br>
This posting is written in both Korean, English. You can select language with 'select box', above this article. excuse my poor english.<br><br>

---

## 프로젝트 개요
이 프로젝트의 목표는 유저가 원하는 버스 위치를 알려주고, 그걸 푸시 알림으로 알려주는 서비스를 만드는 것입니다.<br><br>

---

## 참고 및 사용 라이브러리
1. [**React native**](http://facebook.github.io/react-native/) - facebook<br>
페이스북의 RN. 빠른 앱 구현을 위해서 좋은 프레임워크입니다. 다른 '하이브리드 앱'에 비해 성능도 월등합니다!(실제로 RN은 하이브리드 앱은 아닙니다.)
   1. [**React native Korean Tutorial**](https://www.gitbook.com/book/g6ling/react-native-tutorial-korean)<br>
    페이스북의 공식 RN문서는 충분히 좋습니다..만 한글로 되어 있는 문서가 있으면 더 편하겠죠!
   2. [**React native router flux**](https://github.com/aksonov/react-native-router-flux)<br>
   장면 전환 라우터.
   3. [**React native beacons manager**](https://github.com/MacKentoch/react-native-beacons-manager)<br>
   비콘 리스너
   4. [**React native background timer**](https://github.com/ocetnik/react-native-background-timer)<br>
   푸시 알림을 위한 백그라운드 타이머
   5. [**React native push notification**](https://github.com/zo0r/react-native-push-notification)<br>
   RN을 위한 모바일 네이티브(iOS, Android) 푸시알림 라이브러리
   6. [**React native Elements**](https://github.com/react-native-training/react-native-elements)<br>
   심플하면서 좋은 UI 라이브러리
2. **Raspberry Pi**<br>
학교 랩에서 지원받았습니다. 초기 버전이라 와이파이와 블루투스가 안되는 버전입니다.
   1. **GPS module**<br>
   외부 안테나와 함께 사용.
   2. **Bluetooth Low Energy(BLE) module**<br>
   라즈베리 파이에 블루투스 모듈이 없어서 따로 장착하였습니다. 비콘 브로드캐스팅용.<br><br>

---

## Scene Flow
![](/img/BLE_Bus_Notifier/SceneFlow.png)    

<center><b>장면 구성도</b></center>

장면 전환과 그에 관여하는 함수들은 위의 그림과 같습니다. 밑에서 각 장면에 대한 설명을 보실 수 있습니다.<br><br>

---

## Scenes

| <img src="/img/BLE_Bus_Notifier/Scene0_rangingBeacon.png" width="200">    | <img src="/img/BLE_Bus_Notifier/Scene1_beaconDetected.png"  width="200">    | <img src="/img/BLE_Bus_Notifier/Scene2_destinationSetting.png"  width="200">    |
|=====
| <center> <a href="./#scene-0---beacon-ranging-scene">Scene 0</a> </center>   | <center> <a href="./#scene-1---bus-detail-scene--destination-not-set">Scene 1 </a> </center>    | <center> <a href="./#scene-2---bus-detail-scene--destination-setting"> Scene </a> 2</center>
{: rules="groups"}

### Scene 0 - 비콘 탐색 장면
 첫번째로, '비콘 탐색 장면'입니다. 이 장면에서 앱은 버스의 비콘을 탐색합니다. 적절한 비콘을 찾기 위해서, 이 서비스에서는 고정된 `UUID`값을 사용합니다. 만약 앱이 **단 한개** 의 적절한 `UUID`를 가진 비콘을 찾았다면, 바로 다음 장면으로 넘어갑니다. 만약 앱이 **두개 이상** 의 적절한 `UUID`를 가진 비콘을 찾았다면, 앱은 탐지된 버스의 번호와 위치를 리스트로 보여줍니다. (위의 스크린샷처럼 말입니다.) 저는 버스의 번호와 현 정류장을 구하기 위해 iBeacon 프레임의 `Major`값과 `Minor`값을 사용했습니다.<br><br>

### Scene 1 - 버스 상세 정보 ; 목적지 미설정

 앱이 버스의 비콘을 찾으면, 앱의 비콘 리스너는 리스너의 파라메터에 Major값을 추가하여 해당 비콘만 탐색하도록 합니다. (즉, UUID와 Major 값이 필터링용으로 쓰입니다. 예를 들어 `UUID`: **ABCDEFGH - EEEE - EEEE - EEEE - ABCDEFGHIJKL**, `Major` : **28** 인 비콘을 *리스닝* 합니다. ) 그리고 만약 버스의 위치가 바뀌면, 라즈베리파이에서 비콘의 `Minor`값을 바꿉니다. Minor값, 즉 버스의 현 정류장 위치를 파악하기 위해 유클리드 거리 공식을 사용하였습니다.(반경 거리 측정. 이 부분은 라즈베리 파이 내부에서 구현하였습니다. 즉, 제 담당이 아니었죠. Sorry!)<br>
 앱 사용자는 푸시 알림을 받기 위해 목적지를 설정해야 합니다. 사용자는 '목적지 설정'버튼을 클릭하여 목적지를 설정할 수 있습니다. 누르면 사이드바 메뉴가 뜨죠. <br><br>

### Scene 2 - 버스 상세 정보 ; 목적지 설정 화면

 목적지 설정을 위한 사이드바 메뉴입니다. 이 사이드바 메뉴에서는 목적지를 설정하고, 사용자가 자주 가는 목적지를 보여줍니다. 자주 가는 정류장은 사용자가 목적지로 설정한 기록을 통해 결정됩니다. 이 기록은 RN의 [AsyncStorage](http://facebook.github.io/react-native/docs/asyncstorage.html)(SQLite입니다. 로컬 데이터베이스라고 보시면 됩니다.)를 통해 구현하였습니다. 이는 키`(버스 번호, 버스 정류장)`; 쌍(튜플) -  값`(목적지로 설정한 횟수)`으로 이루어져 있습니다. 즉, 목적지로 설정할 때 마다 1씩 올라가게 되어 있죠. 목적지를 설정하면 앱은 목적지까지 남은 정류장을 카운팅하기 시작합니다.<br><br>

 | <img src="/img/BLE_Bus_Notifier/Scene3_destinationIsSet.png" width="300">    | <img src="/img/BLE_Bus_Notifier/Scene4_BackgroundPush1.png"  width="300">    |
 |=====
 | <center> <a href="./#scene-3---bus-detail-scene--destination-is-set">Scene 3</a> </center>   | <center> <a href="./#scene-4---background-push--destination-is-next-stop"> Scene 4 </a></center>
 {: rules="groups"}


### Scene 3 - 버스 상세 정보 ; 목적지 설정 완료

 목적지가 정해졌다면 앱은 목적지까지 얼마나 남았는지 보여줍니다. 앱은 `refreshState`함수를 통해 [state](http://facebook.github.io/react-native/docs/state.html)를 갱신합니다. 만약 목적지까지 남은 정류장이 두 정류장 이하라면, 앱은 남은 정류장이 몇 되지 않는다고 푸시알림을 보냅니다.<br><br>

### Scene 4 - 백그라운드 푸시 알림 ; 다음 정류장이 목적지 입니다!

 위 스크린샷(장면 4, 푸시 메세지 : *다음 정류장이 목적지 입니다!*) 처럼 푸시 알림을 보냅니다.<br><br>


 | <img src="/img/BLE_Bus_Notifier/Scene5_BackgroundPush_arrived.png" width="300">    | <img src="/img/BLE_Bus_Notifier/Scene6_ForegroundAlert.png"  width="300">    |
 |=====
 | <center> <a href="./#scene-5---background-push--arrived-to-destination">Scene 5</a> </center>   | <center> <a href="./#scene-6---foreground-alert--arrived-to-destination"> Scene 6 </a> </center>
 {: rules="groups"}


### Scene 5 - 백그라운드 푸시 알림 ; 목적지에 도착하였습니다!

앱이 만약 백그라운드에서 돌아간다면 다음과 같이 백그라운드 푸시를 보냅니다.(장면 5, 푸시 메세지 : *목적지에 도착하였습니다!*) <br><br>

### Scene 6 - 포어그라운드 알림 ; 목적지에 도착하였습니다!

 앱이 만약 포어그라운드에서 돌아간다면 다음과 같이 Alert를 보냅니다.(장면 6, Alert 메세지 : *목적지에 도착하였습니다!*) <br><br>
