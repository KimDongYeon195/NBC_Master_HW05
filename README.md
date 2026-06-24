# NBC_Master_HW05

## 필수 구현 기능 - 델리게이트 기반 체력 시스템

### 개요
`ActorComponent` 기반의 체력 컴포넌트를 구현하고,
다이나믹 멀티캐스트 델리게이트를 활용하여
데미지 UI 업데이트와 플레이어 사망 연출을 구현했습니다.

### 1. HealthComponent (UActorComponent)
- 3인칭 캐릭터 클래스에 부착하는 체력 관리 컴포넌트
- `OnTakeAnyDamage` 델리게이트에 `DamageTake` 바인딩
- `FMath::Min(Damage, CurrentHealth)` 으로 오버킬 방지

#### 델리게이트 선언
| `OnHealthDamaged` | Dynamic Multicast (3 Params) | `NewHealth`, `MaxHealth`, `HealthChange` |
| `OnHealthDead` | Dynamic Multicast (1 Param) | `AController* Instigator` |

### 2. UI 업데이트 (OnHealthDamaged)
- `UHealthWidget` C++ 클래스를 생성하여 `BindWidget` 으로 위젯 자동 연결
- `ProgressBar(HPBar)` : 체력 비율에 따른 게이지 업데이트
- `TextBlock(CurrentHPText / MaxHPText)` : 현재 체력 / 최대 체력 수치 표시
- `TSubclassOf<UHealthWidget>` 로 에디터에서 위젯 클래스 선택
- `CreateWidget` → `AddToViewport` 로 게임 시작 시 UI 생성

### 3. 사망 처리 (OnHealthDead)
- `bIsDead` 비트 플래그로 중복 사망 방지
- `DisableMovement()` : 캐릭터 이동 비활성화
- `DisableInput()` : 플레이어 입력 비활성화
- 래그돌 처리
  - `SetSimulatePhysics(true)` : 메시 물리 시뮬레이션 활성화
  - `SetCollisionEnabled(PhysicsOnly)` : 메시 콜리전 물리 전용
  - `CapsuleComponent` 콜리전 비활성화
- `Montage_Play(DeathMontage)` : 사망 애니메이션 재생
- `SetLifeSpan()` : 몽타주 재생 후 액터 제거

---

### 실행 흐름

- ApplyDamage 호출
- OnTakeAnyDamage 발동
- HealthComponent::DamageTake() 실행
    - 데미지 로직 수행
    - UI 업데이트
    - HP <= 0 -> OnHealthDead.Broadcast()
- Character::OnDead() 실행
    - 이동, 입력 비활성화
    - 사망몽타주 재생
    - 캐릭터 제거
