---
layout:       post
title:        "[Study] 네트워크"
date:         2017-10-19
author :      "Lenir"
header-img:   "img/network/3wayHandshake.gif"
catalog:      true
header-mask:  0.8
multilingual: false
mathjax:      true
tags:
- Study
- Network
- OSI 7 Layer
- TCP

comments: true
---

### OSI 7 Layers
![](/img/network/OSI.jpg)
#### 1L - Physical Layer
가장 하부인 물리 계층입니다. 통신을 위한 물리적인 성질(전압, 전선, 핀 레이아웃 등)울 정의합니다.

#### 2L - Data Link Layer
Point-to-Point간의 신뢰성 있는 연결을 보장하기 위한 레이어입니다. Flow Control, Congestion Control, Error Control 등이 주 역할입니다. MAC이 대표적(Media Access Control)이고, MAC Address로 구분됩니다.

#### 3L - Network Layer
네트워크 노드 간의 경로를 찾아주는 레이어입니다. 즉, Inter-Networking을 위한 Router가 존재합니다. IP(Internet Protocol)이 대표적이고, IP Address로 구분됩니다.

#### 4L - Transport Layer
전송 계층. End-to-End간의 신뢰성 있는 연결을 보장하기 위한 레이어. 상위 레이어인 세션, 프리젠테이션, 어플리케이션 레이어들이 하부 레이어들에서 나온 오류를 생각할 필요가 없게 만듬. TCP(Transmission Control Protocol)이 대표적.

#### 5L - Session Layer
TCP/IP 세션을 만들고 없애는 레이어.

#### 6L - Presentation Layer
암/복호화 번역 레이어.

#### 7L - Application Layer
직접 어플리케이션과 연계하는 레이어.

### TCP, Transmission Control Protocol
연결 지향 프로토콜입니다. 패킷 스위칭 방식을 사용하며 발생하는 문제들을 컨트롤합니다. 3-Way Handshacking을 통해 연결을 설정한 후(SYN - ACK,SYN - ACK) 통신을 하는 것이 특징입니다. 대표적인 역할로는 Flow Control, Congestion Control이 있습니다.
#### Flow Control
![](/img/network/tcp-sliding-window.jpg)
수신 측에서 버퍼에 저장할 시간이 필요하기 때문에 송신 측에서는 현재 데이터의 프레임 순서번호, 패리티 코드 등을 같이 보내고, 수신 측에서는 ACK에 받을 프레임 번호를 같이 보내줍니다. 여기서 사용되는 것이 슬라이딩 윈도우인데, 버퍼 사이즈만큼 윈도우가 옮겨가는 것처럼 보면 될 것입니다.



<br><br>
