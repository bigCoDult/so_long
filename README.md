# so_long

**프로젝트 개요**
so_long은 주어진 `.ber` 맵 파일을 읽어 간단한 2D 게임 맵을 생성하고, 플레이어가 아이템을 수집한 후 출구로 향하도록 구현한 교육용 프로젝트입니다.

**프로젝트 의의**
- 파일 I/O를 통해 맵 데이터를 파싱하고, 유효성 검사(벽 배열, 아이템 존재 여부, 출구 및 플레이어 위치)를 수행합니다.
- MiniLibX를 사용하여 윈도우를 생성하고, 이미지(`.xpm`)를 렌더링해 그래픽 출력을 학습합니다.
- 키보드 이벤트 처리(`WASD` 또는 화살표 키)와 충돌 감지를 구현해 플레이어 이동 로직을 이해합니다.
- 게임 상태(아이템 수집, 이동 횟수 표시, 게임 클리어/종료)를 관리하며, 클린업 및 메모리 해제 과정을 경험합니다.

## 구현 기능
- **맵 로드 및 검증**: `validate.c`에서 파일 형식 및 경계 검사
- **그래픽 렌더링**: `draw.c`, `tile` 폴더의 이미지 리소스 사용
- **이벤트 처리**: `hook.c`로 키 입력 및 윈도우 이벤트 처리
- **게임 로직**: `so_long.c`, `util.c`, `end.c`에서 이동, 수집, 종료 조건 구현
- **초기화 및 해제**: `init.c`에서 구조체 초기화, 메모리 해제 로직 포함

## 라이센스
이 프로젝트는 **Beerware License (Revision 42)**를 따릅니다.

```
THE BEER-WARE LICENSE (Revision 42)
As long as you retain this notice you can do anything with this stuff.
If we meet some day, and you think this stuff is worth it, you can buy me a beer in return.
```
