# \[학부 프로젝트 / 웹프로젝트\] 나 혼자 산다

## 목차
1. 개요  
2. 프로젝트 필요성  
3. 프로젝트 개요  
4. 프로젝트 세부구성  
5. 데이터베이스 구조  
6. 기능 구현  
7. 역할분담  
8. 개발환경  
9. 고충과 해결방법  
10. 링크  
---
## 1. 개요

1인가구를 대상으로 각 지역 및 각종 정보에 대해 공유할 수 있는 웹 커뮤니티  
2015년 학부생시절 웹프로그래밍 강의를 듣고 제작한 웹사이트입니다.  
</br>

## 2. 프로젝트 필요성
- 핵가족의 증가에 이어 혼자 사는 사람들의 증가
- 혼자 사는 사람들에 대한 방송프로그램 및 이슈화
- 혼자 사는 사람들의 대부분이 젊은층으로 독립적인 삶에 대한 경험이나 정보가 부족  
그에 따라 정보 공유 및 1인 가구간 교류의 필요성 대두
</br>

## 3. 프로젝트 개요

![](https://blog.kakaocdn.net/dn/4IA2T/btsH637ja0x/866OhZeewWKGboi8bJptz1/img.png)
#### 1) 디자인
- '나 혼자 산다'라는 주거적 의미에서 집 모양의 홈페이지 디자인 구성

#### 2) 로그인 & 로그아웃
- 비로그인 상태에서는 로그인 input이 노출  
- 로그인 상태에서는 로그아웃 이미지가 노출

#### 3) 지도 & 메모
- 메인화면에 지도를 노출해 해당 지역에 대한 시각적인 정보를 제공

#### 4) 게시판
- 각 지역 및 정보에 대한 게시판  
- 사진 첨부기능으로 시각적인 자료게시 가능
</br>

## 4. 프로젝트 세부구성

#### 1) 회원가입
![400x350](https://blog.kakaocdn.net/dn/clhwaE/btsH5wiOOXm/ymkvEinFTLHesekxJOJBY0/img.png)
- 아이디, 비밀번호, 성별, 이메일 정보만으로 간단한 회원가입절차  
- 아이디 중복확인 버튼을 통해 중복확인 가능  
- 회원가입시 DB와 연동하여 아이디 등록  
- 취소 버튼 클릭시 이전 페이지로 이동  
  
#### 2) 로그인 & 로그아웃

![300x200](https://blog.kakaocdn.net/dn/bfka1M/btsH6Njms8w/xKg8V6ucmkcn6FMjQbhXRk/img.png)
- 로그인 되어있는 상태에서만 글 작성이 가능하도록 구현  
- 비로그인 상태에서 글 작성 시도시 알림창과 함께 로그인창 출력  
- 이미 로그인 되어 있는 상태에는 로그인 input 인터페이스 자리에 logout 버튼 출력  
  
#### 3) GoogleMap 연동 & 메모

![](https://blog.kakaocdn.net/dn/cSlQPW/btsH7kVg2Vl/QPbQ3zEfOrVngFVfKKMqKK/img.png)
- 홈페이지 메인에서 노출되는 지도로 시각적인 정보 제공  
- 간단하게 남길 수 있는 한줄 메모 기능  
- GoogleMap과 연동하여 메모 클릭시 해당 지역으로 지도 이동  
  
#### 4) 지역게시판 & 정보게시판

![](https://blog.kakaocdn.net/dn/HCQvo/btsH5X75XjI/0ris6TKKldWcU8dVWCLUi0/img.png)
- 지역 및 정보게시판에 글 작성 및 사진 첨부기능  
- 서버의 업로드 폴더에 사진파일이 전송됨  
- 글 열람시 지역명과 첨부된 사진 등이 노출됨
</br>

## 5. 데이터베이스 구조

![](https://blog.kakaocdn.net/dn/dj4L3A/btsH6ytbUih/nOw5mqsAukgkhjrJXn2QOK/img.png)
- 메모, 정보게시판, 지역게시판에서 현재 로그인한 유저의 ID를 참조  
- 메모에서는 글 내용과 함께 연동된 지도의 위도/경도를 저장  
- 각 게시판에는 첨부된 파일의 경로(업로드된 폴더)를 저장
</br>

## 6. 기능 구현

#### 1) Google maps
- 구글에서 지원해주는 API를 사용하여 메인화면에 구글 지도를 노출  
- 원하는 위도/경도를 중앙에 두기 위해 request객체를 사용
```javascript
<script type="text/javascript">
	function initialize()
    {
    	var map;
        
        var mapLocation = new google.maps.LatLng(
        	<%=request.getParameter("latitude")%>, <%=request.getParameter("longitude")%>);
            
		var mapOptions = {
        	center: mapLocation, // 지도에서 가운데로 위치할 위도와 경도(변수)
            zoom: 14, // 지도 zoom 단계
            mapTypeId: google.maps.MapTypeId.ROADMAP
		};
        
        // id: map-canvas, body에 있는 div태그의 id와 같아야 함
        map = new google.maps.Map(document.getElementById("map-canvas"), mapOptions);
        
        google.maps.event.addDomListener(window, 'load', initialize);
        google.maps.event.addListener(map, 'click', function(event) {
        	getAddressOnClick(event.latLng);
		});
	}
```

#### 2) DB
- 회원가입, 메모, 지역게시판, 정보게시판 등에서 다양한 질의/갱신문 사용  
- liveAlone이라는 이름의 계정을 생성하여 사용(비밀번호 : 1234)  
- mysql-connector-java-5.4.37-bin.jar 라이브러리 연동
```javascript
Class.forName(jdbc_driver);

conn = DriverManager.getConnection(jdbc_url, "liveAlone", "1234");

String sql = "select * from user wehre ID=? and PW=?";
pstmt = conn.prepareStatement(sql);
pstmt.setString(1, ID);
pstmt.setString(2, PW);

rs = pstmt.executeQuery();
```

#### 3) 파일업로드
- 지역게시판, 정보게시판에서 사진 첨부 기능 구현  
- 글 내용등은 데이터베이스에 저장하고 이미지 파일은 서버로 전송  
- cos.jar 라이브러리 연동
```javascript
//file upload
int size = 10 * 1024 * 1024;
String saveFolder="/region_upload/";
ServletContext context = getServletContext();
String uploadPath = context.getRealPath(saveFolder); // 절대경로 가져오기
MultipartRequest multi = new MultipartRequest(
	request, uploadPath, size, "UTF-8", new DefaultFileRenamePolicy());
```

#### 4) 로그인 세션
- 입력된 폼의 값을 데이터베이스에 질의해 해당 ID가 데이터베이스에 존재하면 sessionID값을 설정
```javascript
login_DB LOGIN_DB = new login_DB();

boolean result = LOGIN_DB.loginCheck(id, pw);
if(result) {
  session.setAttribute("sessionID", id);

  String before = request.getHeader("referer");
  response.sendRedirect(before);
}
```

#### 5) 중복확인
- 회원가입 시 아이디 중복확인 요청에 데이터베이스에서 해당 아이디가 존재하는지 질의 후 응답
```javascript
// select 문장을 문자열형태로 구성
String sql = "select * from user where ID=?";
pstmt = conn.prepareStatement(sql);

String insert = request.getParameter("id");
pstmt.setString(1, insert);

// select를 수행하면 데이터정보가 ResultSet클래스의 인스턴스로 리턴됨
ResultSet rs = pstmt.executeQuery();
```
</br>

## 7. 역할분담
2인 합동 프로젝트였으며 제 담당 파트는 아래와 같았습니다.  
- 기획  
- 데이터베이스 구현 및 연결  
- Google Map 연동 및 메모기능 구현  
- 발표ppt작성 및 발표

프로젝트 동료의 역할  
- html과 css
- 게시판
- 사진업로드 기능
</br>

## 8. 개발환경
#### 1) Language  
- JSP  
- JavaScript  
- HTML 및 CSS

#### 2) Database  
- MySQL

#### 3) Server  
- Apache Tomcat
</br>

## 9. 고충과 해결방법

#### 1) 기능구현에는 자신이 있었지만 디자인능력이 없었다.
당시 jsp기반 웹프로그래밍 강의를 듣고 내부 로직은 구현할 능력이 있었지만 html이나 css같은 프론트엔드 지식이 전무한 상황이었습니다. 그래서 당시 웹디자인을 공부하던 동기와 함께 프로젝트를 진행했고 역할분담 후 각 분야에서의 구현이 수월하게 진행됐습니다.  
이를 통해 팀원간의 협업과 역할분담에 대해 배우고 한 분야에 대한 전문화의 가치를 깨닫게 되었습니다.  
</br>

## 10. 링크

#### 1) Github
https://github.com/batsalee/UniversityData/tree/main/%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8/%EB%82%98%20%ED%98%BC%EC%9E%90%20%EC%82%B0%EB%8B%A4](https://github.com/batsalee/UniversityData/tree/main/%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8/%EB%82%98%20%ED%98%BC%EC%9E%90%20%EC%82%B0%EB%8B%A4)

#### 2) Blog
[https://smallpants.tistory.com/266](https://smallpants.tistory.com/266)
