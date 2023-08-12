# 나 혼자 산다
1인가구를 대상으로 각 지역 및 각종 정보에 대해 공유할 수 있는 웹 커뮤니티</br> 

---

# 메모
대학교시절 강의 웹 프로그래밍을 들으면서 제작해보고자 하여 만들어본 웹사이트입니다.</br>
2인 합동 프로젝트였고 제 담당 파트는 아래와 같았습니다.</br>
\- 기획</br>
\- 데이터베이스 구현 및 연결</br>
\- Google Map 연동 및 메모기능 구현</br>
\- 발표ppt작성 및 발표</br>

그 외 디자인부분 및 게시판 및 사진업로드 기능 등은 프로젝트 동료의 역할이었습니다.

---

# 필요성
\- 핵가족의 증가에 이어 혼자 사는 사람들의 증가</br>
\- 혼자 사는 사람들에 대한 방송프로그램 및 이슈화</br>
\- 혼자 사는 사람들의 대부분이 젊은층으로 독립적인 삶에 대한 경험이나 정보가 부족</br>

그에 따라 정보 공유 및 1인 가구간 교류의 필요성 대두</br>

---

# 프로젝트 개요
<img width="50%" src="https://github.com/batsalee/UniversityData/assets/109213754/8e1b7dc5-784d-46c2-99ab-736120a15a47"/>

1) 디자인</br>
\- '나 혼자 산다'라는 주거적 의미에서 집 모양의 홈페이지 디자인 구성</br>

2) 로그인 & 로그아웃</br>
\- 비로그인 상태에서는 로그인 input이 노출</br>
\- 로그인 상태에서는 로그아웃 이미지가 노출</br>

3) 지도 & 메모</br>
\- 메인화면에 지도를 노출해 해당 지역에 대한 시각적인 정보를 제공</br>

4) 게시판</br>
\- 각 지역 및 정보에 대한 게시판</br>
\- 사진 첨부기능으로 시각적인 자료게시 가능</br>

---

# 세부구성
<img width="50%" src="https://github.com/batsalee/UniversityData/assets/109213754/7e927fb0-f306-4ad1-ac5e-170d81dbeeda"/>

1) 회원가입</br>
\- 아이디, 비밀번호, 성별, 이메일 정보만으로 간단한 회원가입절차</br>
\- 아이디 중복확인 버튼을 통해 중복확인 가능</br>
\- 회원가입시 DB와 연동하여 아이디 등록</br>
\- 취소 버튼 클릭시 이전 페이지로 이동</br></br>

<img width="50%" src="https://github.com/batsalee/UniversityData/assets/109213754/a41ccacc-eb1e-4a96-af9a-b56e9a8a4c8e"/>

2) 로그인 & 로그아웃</br>
\- 로그인 되어있는 상태에서만 글 작성이 가능하도록 구현</br>
\- 비로그인 상태에서 글 작성 시도시 알림창과 함께 로그인창 출력</br>
\- 이미 로그인 되어 있는 상태에는 로그인 input 인터페이스 자리에 logout 버튼 출력</br></br>

<img width="50%" src="https://github.com/batsalee/UniversityData/assets/109213754/d3ff2af6-45b2-4cb8-87d2-1fdcf466fa4e"/>

3) GoogleMap 연동 & 메모</br>
\- 홈페이지 메인에서 노출되는 지도로 시각적인 정보 제공</br>
\- 간단하게 남길 수 있는 한줄 메모 기능</br>
\- GoogleMap과 연동하여 메모 클릭시 해당 지역으로 지도 이동</br></br>

<img width="100%" src="https://github.com/batsalee/UniversityData/assets/109213754/69f5b2e8-6614-412c-98f2-d81c16817c51"/>

4) 지역게시판 & 정보게시판</br>
\- 지역 및 정보게시판에 글 작성 및 사진 첨부기능</br>
\- 서버의 업로드 폴더에 사진파일이 전송됨</br>
\- 글 열람시 지역명과 첨부된 사진 등이 노출됨</br>

---

# 데이터베이스 구조
<img width="50%" src="https://github.com/batsalee/UniversityData/assets/109213754/be86a8b6-c2fe-4f4b-924a-93e959696a55"/>

\- 메모, 정보게시판, 지역게시판에서 현재 로그인한 유저의 ID를 참조</br>
\- 메모에서는 글 내용과 함께 연동된 지도의 위도/경도를 저장</br>
\- 각 게시판에는 첨부된 파일의 경로(업로드된 폴더)를 저장</br>

---

# 기능 구현
1) Google maps</br>
\- 구글에서 지원해주는 API를 사용하여 메인화면에 구글 지도를 노출</br>
\- 원하는 위도/경도를 중앙에 두기 위해 request객체를 사용</br>

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

</br>2) DB</br>
\- 회원가입, 메모, 지역게시판, 정보게시판 등에서 다양한 질의/갱신문 사용</br>
\- liveAlone이라는 이름의 계정을 생성하여 사용(비밀번호 : 1234)</br>
\- mysql-connector-java-5.4.37-bin.jar 라이브러리 연동</br>
```java
Class.forName(jdbc_driver);

conn = DriverManager.getConnection(jdbc_url, "liveAlone", "1234");

String sql = "select * from user wehre ID=? and PW=?";
pstmt = conn.prepareStatement(sql);
pstmt.setString(1, ID);
pstmt.setString(2, PW);

rs = pstmt.executeQuery();
```

</br>3) 파일업로드</br>
\- 지역게시판, 정보게시판에서 사진 첨부 기능 구현</br>
\- 글 내용등은 데이터베이스에 저장하고 이미지 파일은 서버로 전송</br>
\- cos.jar 라이브러리 연동</br>
```java
//file upload
int size = 10 * 1024 * 1024;
String saveFolder="/region_upload/";
ServletContext context = getServletContext();
String uploadPath = context.getRealPath(saveFolder); // 절대경로 가져오기
MultipartRequest multi = new MultipartRequest(
	request, uploadPath, size, "UTF-8", new DefaultFileRenamePolicy());
```

</br>4) 로그인 세션</br>
\- 입력된 폼의 값을 데이터베이스에 질의해 해당 ID가 데이터베이스에 존재하면 sessionID값을 설정</br>
```java
login_DB LOGIN_DB = new login_DB();

boolean result = LOGIN_DB.loginCheck(id, pw);
if(result) {
  session.setAttribute("sessionID", id);

  String before = request.getHeader("referer");
  response.sendRedirect(before);
}
```

</br>5) 중복확인</br>
\- 회원가입 시 아이디 중복확인 요청에 데이터베이스에서 해당 아이디가 존재하는지 질의 후 응답
```java
// select 문장을 문자열형태로 구성
String sql = "select * from user where ID=?";
pstmt = conn.prepareStatement(sql);

String insert = request.getParameter("id");
pstmt.setString(1, insert);

// select를 수행하면 데이터정보가 ResultSet클래스의 인스턴스로 리턴됨
ResultSet rs = pstmt.executeQuery();
```

---

# 개발환경
1) Language</br>
\- JSP</br>
\- JavaScript</br>
\- HTML 및 CSS</br>

2) Database</br>
\- MySQL</br>

3) Server</br>
\- Apache Tomcat</br>

---
