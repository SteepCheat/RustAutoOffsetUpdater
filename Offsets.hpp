#include <vector>
#include <string>

auto oBaseGameMode = 0;
auto oBaseGameModeHardCore = 0;
auto oConvarGraphics = 0;
auto oConvarClient = 0;
auto oConsoleSystem = 0;
auto oConvarAdmin = 0;
auto oOcclusionCulling = 0;
auto oConVarCulling = 0;

auto oPlayerFlag = 0;
auto oPlayerMovement = 0;
auto oActiveUID = 0;
auto oPlayerInventory = 0;
auto oContainerBelt = 0;
auto oBeltContentList = 0;
auto oHeld = 0;
auto oRecoilProperties = 0;
auto oRecoilYawMin = 0;
auto oRecoilYawMax = 0;
auto oRecoilPitchMin = 0;
auto oRecoilPitchMax = 0;
auto oAimconeCurveScale = 0;
auto oStancePenalty = 0;
auto oAimCone = 0;
auto oHipAimCone = 0;
auto oAimconePenaltyPerShot = 0;
auto oAutomatic = 0;
auto oCapsuleHeight = 0;
auto oCapsuleCenter = 0;
auto oGroundAngle = 0;
auto oGroundAngleNew = 0;
auto oGravityMultiplier = 0;

struct OffsetInfo {
	std::string class_name;
	std::string offset_name;
	std::string hex_str;
};

std::vector<OffsetInfo> offsets = {
{"public class BasePlayer : BaseCombatEntity, LootPanel.IHasLootPanel, IIdealSlotEntity", "public BasePlayer.PlayerFlags playerFlags;"},
{"public class BasePlayer : BaseCombatEntity, LootPanel.IHasLootPanel, IIdealSlotEntity", "public BaseMovement movement;"},
{"public class BasePlayer : BaseCombatEntity, LootPanel.IHasLootPanel, IIdealSlotEntity", "private uint clActiveItem;"},
{"public class BasePlayer : IDisposable, Pool.IPooled, IProto", "public PlayerInventory inventory;"},
{"public class PlayerInventory : EntityComponent<BasePlayer>", "public ItemContainer containerBelt;"},
{"public class ItemContainer : IDisposable, Pool.IPooled, IProto", "public List<Item> contents;"},
{"public class Item", "private EntityRef heldEntity"},
{"public class BaseProjectile : AttackEntity", "public RecoilProperties recoil;"},
{"public class RecoilProperties : ScriptableObject", "public float recoilYawMin;"},
{"public class RecoilProperties : ScriptableObject", "public float recoilYawMax;"},
{"public class RecoilProperties : ScriptableObject", "public float recoilPitchMin;"},
{"public class RecoilProperties : ScriptableObject", "public float recoilPitchMax;"},
{"public class RecoilProperties : ScriptableObject", "public float aimconeCurveScale;"},
{"public class BaseProjectile : AttackEntity", "private float stancePenalty;"},
{"public class BaseProjectile : AttackEntity", "public float aimCone;"},
{"public class BaseProjectile : AttackEntity", "public float hipAimCone;"},
{"public class BaseProjectile : AttackEntity", "public float aimconePenaltyPerShot;"},
{"public class BaseProjectile : AttackEntity", "public bool automatic;"},
{"public class PlayerWalkMovement : BaseMovement", "public float capsuleHeight;"},
{"public class PlayerWalkMovement : BaseMovement", "public float capsuleCenter;"},
{"public class PlayerWalkMovement : BaseMovement", "groundAngle;"},
{"public class PlayerWalkMovement : BaseMovement", "groundAngleNew;"},
{"public class PlayerWalkMovement : BaseMovement", "public float gravityMultiplier;"}
};