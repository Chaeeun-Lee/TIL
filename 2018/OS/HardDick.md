# 하드디스크
## 구조
### Head
뾰족하게 생긴 물리적인 도구. 하드디스크는 여러 장의 판으로 이루어져 있고, 그 판을 `플래터(Platter)`라고 한다. 헤드는 플래터를 읽고 기록하는 역할을 한다. 작업을 할 때 헤드는 움직이지 않고 플래터가 움직인다.
### Track
정보가 저장되는 일정한 간격의 동심원이다.
### Sector
트랙의 구간을 일정하게 나눈 것이다. 섹터 하나당 512bytes가 저장된다.
### Cylinder
중심부로부터 일정하게 떨어져 있는 같은 트랙의 모임이다.
### Cluster
섹터의 모음. 운영체제가 읽고 쓰는 기본 단위이다. 블록이라고도 부른다.
## File vs Directory
### File
1. 관련된 레코드들의 집합
2. 파일 시스템: 파일들을 관리하는 운영체제의 한 부분으로 파일 생성 시 디스크 내에 저장되는 위치(장소)와 효과적인 접근 방법 등을 고려해야 한다.
3. 파일의 속성(메타데이터)
    1. 파일의 이름, 종류, 크기
    2. 파일 생성 날짜, 최근 파일 접근 시간, 갱신 시간
    3. 파일의 소유자, 접근 권한
    4. 파일의 저장 위치 등
### Directory
1. 논리적으로 관련된 파일들이나 다른 파일 디렉토리에 대한 정보를 모아놓은 곳. 트리 구조를 가지고 있다.
2. 계층 디렉토리: 한 디렉토리 내에 하위 디렉토리 생성, 삭제 가능. 서로 다른 디렉토리에 파일을 분류하여 관리.

메타데이터(파일의 속성)를 저장해 둔 파일을 디렉토리라 부른다는 점에서 파일과 디렉토리에 차이가 생긴다.
## 파일 할당
### 연속 할당
디스크상의 연속된 블록에 파일을 할당하는 것.
- 장점: 디스크가 읽어 들어갈 때 이동 경로를 최소화할 수 있다. 빠른 I/O의 성능을 가질 수 있으며, 동영상과 같은 실시간인 발표들에 적합하다.
- 단점: 특정 파일이 삭제되면 hole이 발생하여 **외부 단편화**가 생긴다. 또한 뒤에 다른 파일이 있어 파일 크기 수정이 불가하다.
### 비연속 할당
디스크상의 연속되지 않은 각각 다른 블록에 파일을 할당하는 것.
#### 연결 할당
각 블록마다 다음 블록 주소를 저장하고 있는 방식.
- 장점: 파일 크기가 고정되어 있지 않다. 외부 단편화가 발생하지 않기 때문에 주기적 밀집화가 필요 없다.
    - **주기적 밀집화**란 외부 단편화가 발생할 때 빈 공간을 채우기 위해 파일들을 밀집시키는 것을 말한다.
- 단점: 순차적 접근 파일에만 효율적인 방식이다.
#### FAT 할당
각 디스크 블록마다 한 개의 항목을 가지고 있고, 이 항목은 디스크 블록 번호를 색인으로 찾는다.
- 장점: 호환성이 좋고 단순하다. 또한 저용량 볼륨에 좋다.
- 단점: 보안에 취약하다. 또한 대용량 볼륨을 비효율적으로 이용하게 된다.
#### 색인 할당
파일당 최소 한 개의 인덱스 블록을 가지고 있는 방식. 인덱스 블록에 파일 데이터를 가지고 있는 블록의 주소들이 순서대로 저장되어 있다.
- 장점: 외부 단편화가 발생하지 않는다. 또한 순차 접근, 직접 접근이 모두 가능하다.
- 단점: 인덱스 블록을 사용하게 되므로 블록 하나를 낭비하게 되는 셈이다. 인덱스 블록 내에 인덱스가 많이 저장되지 않아도 인덱스 블록 하나를 써야 한다. 결국 내부 단편화가 발생하게 된다.