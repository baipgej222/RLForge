#pragma once

// Rocket League (1.31) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x4)
#endif

namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class GameFramework.DynamicSpriteComponent
// 0x0040 (0x024C - 0x020C)
class UDynamicSpriteComponent : public USpriteComponent
{
public:
	struct FInterpCurveFloat                           AnimatedScale;                                            // 0x020C(0x0010) (CPF_Edit, CPF_NeedCtorLink)
	struct FInterpCurveLinearColor                     AnimatedColor;                                            // 0x021C(0x0010) (CPF_Edit, CPF_NeedCtorLink)
	struct FInterpCurveVector2D                        AnimatedPosition;                                         // 0x022C(0x0010) (CPF_Edit, CPF_NeedCtorLink)
	struct FVector                                     LocationOffset;                                           // 0x023C(0x000C) (CPF_Edit)
	int                                                LoopCount;                                                // 0x0248(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.DynamicSpriteComponent");
		return ptr;
	}

};


// Class GameFramework.FrameworkGame
// 0x000C (0x03EC - 0x03E0)
class AFrameworkGame : public AGameInfo
{
public:
	TArray<struct FRequiredMobileInputConfig>          RequiredMobileInputConfigs;                               // 0x03E0(0x000C) (CPF_Config, CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.FrameworkGame");
		return ptr;
	}

};


// Class GameFramework.GameTypes
// 0x0000 (0x003C - 0x003C)
class UGameTypes : public UObject
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameTypes");
		return ptr;
	}

};


// Class GameFramework.GameAIController
// 0x0038 (0x03E4 - 0x03AC)
class AGameAIController : public AAIController
{
public:
	class UGameAICommand*                              CommandList;                                              // 0x03AC(0x0004) (CPF_Edit, CPF_Const, CPF_Transient, CPF_EditInline)
	unsigned long                                      bHasRunawayCommandList : 1;                               // 0x03B0(0x0004) (CPF_Transient)
	unsigned long                                      bAILogging : 1;                                           // 0x03B0(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bAILogToWindow : 1;                                       // 0x03B0(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bFlushAILogEachLine : 1;                                  // 0x03B0(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bMapBasedLogName : 1;                                     // 0x03B0(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bAIDrawDebug : 1;                                         // 0x03B0(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bAIBroken : 1;                                            // 0x03B0(0x0004) (CPF_Transient)
	class AFileLog*                                    AILogFile;                                                // 0x03B4(0x0004) (CPF_Transient)
	float                                              DebugTextMaxLen;                                          // 0x03B8(0x0004) (CPF_Edit)
	TArray<struct FAICmdHistoryItem>                   CommandHistory;                                           // 0x03BC(0x000C) (CPF_Edit, CPF_Const, CPF_Transient, CPF_NeedCtorLink)
	int                                                CommandHistoryNum;                                        // 0x03C8(0x0004) (CPF_Edit, CPF_Config)
	TArray<struct FName>                               AILogFilter;                                              // 0x03CC(0x000C) (CPF_Edit, CPF_Config, CPF_NeedCtorLink)
	struct FString                                     DemoActionString;                                         // 0x03D8(0x000C) (CPF_Net, CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameAIController");
		return ptr;
	}


	struct FString GetActionString();
	void SetDesiredRotation(const struct FRotator& TargetDesiredRotation, bool InLockDesiredRotation, bool InUnlockWhenReached, float InterpolationTime);
	void AILog_Internal(const struct FString& LogText, const struct FName& LogCategory, bool bForce);
	void RecordDemoAILog(const struct FString& LogText);
	void Destroyed();
	void ReachedIntermediateMoveGoal();
	void ReachedMoveGoal();
	float GetDestinationOffset();
	class UGameAICommand* GetAICommandInStack(class UClass* InClass);
	class UGameAICommand* FindCommandOfClass(class UClass* SearchClass);
	void DumpCommandStack();
	void CheckCommandCount();
	class UGameAICommand* GetActiveCommand();
	bool AbortCommand(class UGameAICommand* AbortCmd, class UClass* AbortClass);
	void PopCommand(class UGameAICommand* ToBePoppedCommand);
	void PushCommand(class UGameAICommand* NewCommand);
	void AllCommands(class UClass* BaseClass, class UGameAICommand** Cmd);
};


// Class GameFramework.GameAICommand
// 0x001C (0x0058 - 0x003C)
class UGameAICommand : public UAICommandBase
{
public:
	class UGameAICommand*                              ChildCommand;                                             // 0x003C(0x0004) (CPF_Edit, CPF_Const, CPF_Transient, CPF_EditInline)
	struct FName                                       ChildStatus;                                              // 0x0040(0x0008) (CPF_Edit, CPF_Const, CPF_Transient)
	class AGameAIController*                           GameAIOwner;                                              // 0x0048(0x0004) (CPF_Edit, CPF_Transient)
	struct FName                                       Status;                                                   // 0x004C(0x0008) (CPF_Edit, CPF_Transient)
	unsigned long                                      bAllowNewSameClassInstance : 1;                           // 0x0054(0x0004)
	unsigned long                                      bReplaceActiveSameClassInstance : 1;                      // 0x0054(0x0004)
	unsigned long                                      bAborted : 1;                                             // 0x0054(0x0004) (CPF_Transient)
	unsigned long                                      bIgnoreNotifies : 1;                                      // 0x0054(0x0004)
	unsigned long                                      bIgnoreStepAside : 1;                                     // 0x0054(0x0004)
	unsigned long                                      bPendingPop : 1;                                          // 0x0054(0x0004) (CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameAICommand");
		return ptr;
	}


	bool HandlePathObstruction(class AActor* BlockedBy);
	bool MoveUnreachable(const struct FVector& AttemptedDest, class AActor* AttemptedTarget);
	void NotifyNeedRepath();
	struct FString GetDebugVerboseText();
	void GetDebugOverheadText(class APlayerController* PC, TArray<struct FString>* OutText);
	void DrawDebug(class AHUD* H, const struct FName& Category);
	struct FString GetDumpString();
	void Resumed(const struct FName& OldCommandName);
	void Paused(class UGameAICommand* NewCommand);
	void Popped();
	void Pushed();
	void PostPopped();
	void PrePushed(class AGameAIController* AI);
	bool AllowStateTransitionTo(const struct FName& StateName);
	bool AllowTransitionTo(class UClass* AttemptCommand);
	void Tick(float DeltaTime);
	bool ShouldIgnoreNotifies();
	void InternalTick(float DeltaTime);
	void InternalResumed(const struct FName& OldCommandName);
	void InternalPaused(class UGameAICommand* NewCommand);
	void InternalPopped();
	void InternalPushed();
	void InternalPrePushed(class AGameAIController* AI);
	bool STATIC_InitCommand(class AGameAIController* AI);
	bool STATIC_InitCommandUserActor(class AGameAIController* AI, class AActor* UserActor);
};


// Class GameFramework.GameCameraBlockingVolume
// 0x0000 (0x0240 - 0x0240)
class AGameCameraBlockingVolume : public ABlockingVolume
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCameraBlockingVolume");
		return ptr;
	}

};


// Class GameFramework.GamePlayerController
// 0x0010 (0x05E0 - 0x05D0)
class AGamePlayerController : public APlayerController
{
public:
	unsigned long                                      bWarnCrowdMembers : 1;                                    // 0x05D0(0x0004)
	unsigned long                                      bDebugCrowdAwareness : 1;                                 // 0x05D0(0x0004) (CPF_Edit)
	unsigned long                                      bIsWarmupPaused : 1;                                      // 0x05D0(0x0004) (CPF_Transient)
	float                                              AgentAwareRadius;                                         // 0x05D4(0x0004)
	struct FName                                       CurrentSoundMode;                                         // 0x05D8(0x0008) (CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GamePlayerController");
		return ptr;
	}


	void ClientColorFade(const struct FColor& FadeColor, unsigned char FromAlpha, unsigned char ToAlpha, float FadeTime);
	void WarmupPause(bool bDesiredPauseState);
	bool CanUnpauseWarmup();
	void GetCurrentMovie(struct FString* MovieName);
	void ClientStopMovie(float DelayInSeconds, bool bAllowMovieToFinish, bool bForceStopNonSkippable, bool bForceStopLoadingMovie);
	void ClientPlayMovie(const struct FString& MovieName, int InStartOfRenderingMovieFrame, int InEndOfRenderingMovieFrame, bool bRestrictPausing, bool bPlayOnceFromStream, bool bOnlyBackButtonSkipsMovie);
	void STATIC_KeepPlayingLoadingMovie();
	void STATIC_ShowLoadingMovie(bool bShowMovie, bool bPauseAfterHide, float PauseDuration, float KeepPlayingDuration, bool bOverridePreviousDelays);
	void SetSoundMode(const struct FName& InSoundModeName);
	void DoForceFeedbackForScreenShake(class UCameraShake* ShakeData, float Scale);
	void NotifyCrowdAgentInRadius(class AGameCrowdAgent* Agent);
	void NotifyCrowdAgentRefresh();
	void CrowdDebug(bool bEnabled);
	int GetUIPlayerIndex();
	void OnToggleMouseCursor(class USeqAct_ToggleMouseCursor* inAction);
};


// Class GameFramework.GameCheatManager
// 0x0014 (0x0068 - 0x0054)
class UGameCheatManager : public UCheatManager
{
public:
	class ADebugCameraController*                      DebugCameraControllerRef;                                 // 0x0054(0x0004)
	class UClass*                                      DebugCameraControllerClass;                               // 0x0058(0x0004)
	struct FString                                     DebugCameraControllerClassName;                           // 0x005C(0x000C) (CPF_Config, CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCheatManager");
		return ptr;
	}


	void OnRequestComplete(class UHttpRequestInterface* OriginalRequest, class UHttpResponseInterface* Response, bool bDidSucceed);
	void TestHttp(const struct FString& Verb, const struct FString& Payload, const struct FString& URL, bool bSendParallelRequest);
	void EnableDebugCamera(bool bEnableDebugText);
	void TeleportPawnToCamera(bool bToggleDebugCameraOff);
	void ToggleDebugCamera(bool bDrawDebugText);
	void PatchDebugCameraController();
};


// Class GameFramework.GameCrowdAgent
// 0x0208 (0x041C - 0x0214)
class AGameCrowdAgent : public ACrowdAgentBase
{
public:
	struct FPointer                                    VfTable_IInterface_RVO;                                   // 0x0214(0x0004) (CPF_Const, CPF_Native, CPF_NoExport)
	class UGameCrowdGroup*                             MyGroup;                                                  // 0x0218(0x0004)
	struct FVector                                     PreferredVelocity;                                        // 0x021C(0x000C)
	struct FVector                                     PendingVelocity;                                          // 0x0228(0x000C)
	class AGameCrowdDestination*                       CurrentDestination;                                       // 0x0234(0x0004)
	class AGameCrowdDestination*                       BehaviorDestination;                                      // 0x0238(0x0004)
	class AGameCrowdDestination*                       PreviousDestination;                                      // 0x023C(0x0004)
	float                                              InterpZTranslation;                                       // 0x0240(0x0004)
	int                                                Health;                                                   // 0x0244(0x0004) (CPF_Edit)
	float                                              DeadBodyDuration;                                         // 0x0248(0x0004) (CPF_Edit)
	class UDynamicLightEnvironmentComponent*           LightEnvironment;                                         // 0x024C(0x0004) (CPF_Const, CPF_ExportObject, CPF_EditConst, CPF_Component, CPF_EditInline)
	int                                                ConformTraceFrameCount;                                   // 0x0250(0x0004) (CPF_Transient)
	TArray<struct FNearbyDynamicItem>                  NearbyDynamics;                                           // 0x0254(0x000C) (CPF_Transient, CPF_NeedCtorLink)
	unsigned long                                      bUniformScale : 1;                                        // 0x0260(0x0004)
	unsigned long                                      bCheckForObstacles : 1;                                   // 0x0260(0x0004) (CPF_Edit)
	unsigned long                                      bUseNavMeshPathing : 1;                                   // 0x0260(0x0004) (CPF_Edit)
	unsigned long                                      bWantsSeePlayerNotification : 1;                          // 0x0260(0x0004)
	unsigned long                                      bAllowPitching : 1;                                       // 0x0260(0x0004) (CPF_Edit)
	unsigned long                                      bHitObstacle : 1;                                         // 0x0260(0x0004)
	unsigned long                                      bBadHitNormal : 1;                                        // 0x0260(0x0004)
	unsigned long                                      bSimulateThisTick : 1;                                    // 0x0260(0x0004)
	unsigned long                                      bPotentialEncounter : 1;                                  // 0x0260(0x0004)
	unsigned long                                      bIsPanicked : 1;                                          // 0x0260(0x0004)
	unsigned long                                      bWantsGroupIdle : 1;                                      // 0x0260(0x0004)
	unsigned long                                      bPreferVisibleDestination : 1;                            // 0x0260(0x0004) (CPF_Edit)
	unsigned long                                      bPreferVisibleDestinationOnSpawn : 1;                     // 0x0260(0x0004) (CPF_Edit)
	unsigned long                                      bHasNotifiedSpawner : 1;                                  // 0x0260(0x0004)
	unsigned long                                      bIsInSpawnPool : 1;                                       // 0x0260(0x0004)
	unsigned long                                      bPaused : 1;                                              // 0x0260(0x0004) (CPF_Edit)
	TEnumAsByte<EConformType>                          ConformType;                                              // 0x0264(0x0001) (CPF_Edit)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0265(0x0003) MISSED OFFSET
	float                                              ConformTraceDist;                                         // 0x0268(0x0004) (CPF_Edit)
	int                                                ConformTraceInterval;                                     // 0x026C(0x0004) (CPF_Edit)
	int                                                CurrentConformTraceInterval;                              // 0x0270(0x0004)
	float                                              LastGroundZ;                                              // 0x0274(0x0004)
	float                                              AwareRadius;                                              // 0x0278(0x0004) (CPF_Edit)
	float                                              AvoidOtherRadius;                                         // 0x027C(0x0004) (CPF_Edit)
	TArray<struct FAvoidOtherSampleItem>               AvoidOtherSampleList;                                     // 0x0280(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              PENALTY_COEFF_ANGLETOGOAL;                                // 0x028C(0x0004) (CPF_Edit)
	float                                              PENALTY_COEFF_ANGLETOVEL;                                 // 0x0290(0x0004) (CPF_Edit)
	float                                              PENALTY_COEFF_MAG;                                        // 0x0294(0x0004) (CPF_Edit)
	float                                              MIN_PENALTY_THRESHOLD;                                    // 0x0298(0x0004) (CPF_Edit)
	float                                              LastProgressTime;                                         // 0x029C(0x0004) (CPF_Edit)
	float                                              LastFallbackActiveTime;                                   // 0x02A0(0x0004) (CPF_Edit)
	float                                              MaxPathLaneValue;                                         // 0x02A4(0x0004) (CPF_Edit)
	float                                              CurrentPathLaneValue;                                     // 0x02A8(0x0004) (CPF_Edit)
	int                                                ExtraPathCost;                                            // 0x02AC(0x0004) (CPF_Edit)
	float                                              RotateToTargetSpeed;                                      // 0x02B0(0x0004) (CPF_Edit)
	float                                              MaxYawRate;                                               // 0x02B4(0x0004) (CPF_Edit)
	struct FVector                                     MeshMinScale3D;                                           // 0x02B8(0x000C) (CPF_Edit)
	struct FVector                                     MeshMaxScale3D;                                           // 0x02C4(0x000C) (CPF_Edit)
	float                                              EyeZOffset;                                               // 0x02D0(0x0004)
	float                                              ProximityLODDist;                                         // 0x02D4(0x0004) (CPF_Edit)
	float                                              VisibleProximityLODDist;                                  // 0x02D8(0x0004) (CPF_Edit)
	struct FVector                                     LastKnownGoodPosition;                                    // 0x02DC(0x000C)
	float                                              GroundOffset;                                             // 0x02E8(0x0004) (CPF_Edit)
	struct FVector                                     IntermediatePoint;                                        // 0x02EC(0x000C)
	struct FVector                                     SearchExtent;                                             // 0x02F8(0x000C)
	class UClass*                                      NavigationHandleClass;                                    // 0x0304(0x0004)
	class UNavigationHandle*                           NavigationHandle;                                         // 0x0308(0x0004)
	int                                                ObstacleCheckCount;                                       // 0x030C(0x0004)
	float                                              WalkableFloorZ;                                           // 0x0310(0x0004)
	float                                              LastPathingAttempt;                                       // 0x0314(0x0004)
	float                                              LastUpdateTime;                                           // 0x0318(0x0004)
	float                                              NotVisibleLifeSpan;                                       // 0x031C(0x0004) (CPF_Edit)
	class AGameCrowdAgent*                             MyArchetype;                                              // 0x0320(0x0004)
	float                                              MaxWalkingSpeed;                                          // 0x0324(0x0004) (CPF_Edit)
	float                                              MaxRunningSpeed;                                          // 0x0328(0x0004) (CPF_Edit)
	float                                              MaxSpeed;                                                 // 0x032C(0x0004)
	TArray<struct FRecentInteraction>                  RecentInteractions;                                       // 0x0330(0x000C) (CPF_NeedCtorLink)
	float                                              BeaconMaxDist;                                            // 0x033C(0x0004)
	struct FVector                                     BeaconOffset;                                             // 0x0340(0x000C)
	class UTexture2D*                                  BeaconTexture;                                            // 0x034C(0x0004) (CPF_Const)
	struct FLinearColor                                BeaconColor;                                              // 0x0350(0x0010) (CPF_Const)
	class USoundCue*                                   AmbientSoundCue;                                          // 0x0360(0x0004) (CPF_Edit)
	class UAudioComponent*                             AmbientSoundComponent;                                    // 0x0364(0x0004) (CPF_ExportObject, CPF_Component, CPF_EditInline)
	class UGameCrowdAgentBehavior*                     CurrentBehavior;                                          // 0x0368(0x0004)
	float                                              CurrentBehaviorActivationTime;                            // 0x036C(0x0004)
	TArray<struct FBehaviorEntry>                      EncounterAgentBehaviors;                                  // 0x0370(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<struct FBehaviorEntry>                      SeePlayerBehaviors;                                       // 0x037C(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              MaxSeePlayerDistSq;                                       // 0x0388(0x0004)
	float                                              SeePlayerInterval;                                        // 0x038C(0x0004) (CPF_Edit)
	TArray<struct FBehaviorEntry>                      SpawnBehaviors;                                           // 0x0390(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<struct FBehaviorEntry>                      UneasyBehaviors;                                          // 0x039C(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<struct FBehaviorEntry>                      AlertBehaviors;                                           // 0x03A8(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<struct FBehaviorEntry>                      PanicBehaviors;                                           // 0x03B4(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<struct FBehaviorEntry>                      RandomBehaviors;                                          // 0x03C0(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<struct FBehaviorEntry>                      TakeDamageBehaviors;                                      // 0x03CC(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              RandomBehaviorInterval;                                   // 0x03D8(0x0004) (CPF_Edit)
	float                                              ForceUpdateTime;                                          // 0x03DC(0x0004)
	float                                              ReachThreshold;                                           // 0x03E0(0x0004)
	TArray<struct FBehaviorEntry>                      GroupWaitingBehaviors;                                    // 0x03E4(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              DesiredGroupRadius;                                       // 0x03F0(0x0004) (CPF_Edit)
	float                                              DesiredGroupRadiusSq;                                     // 0x03F4(0x0004)
	float                                              MaxLOSLifeDistanceSq;                                     // 0x03F8(0x0004)
	TScriptInterface<class UGameCrowdSpawnerInterface> MySpawner;                                                // 0x03FC(0x0008)
	struct FVector                                     SpawnOffset;                                              // 0x0404(0x000C)
	float                                              InitialLastRenderTime;                                    // 0x0410(0x0004)
	struct FColor                                      DebugAgentColor;                                          // 0x0414(0x0004) (CPF_Edit)
	class AGameCrowdDestination*                       DebugSpawnDest;                                           // 0x0418(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdAgent");
		return ptr;
	}


	void InitDebugColor();
	struct FString GetBehaviorString();
	struct FString GetDestString();
	void PostRenderFor(class APlayerController* PC, class UCanvas* Canvas, const struct FVector& CameraPosition, const struct FVector& CameraDir);
	void NativePostRenderFor(class APlayerController* PC, class UCanvas* Canvas, const struct FVector& CameraPosition, const struct FVector& CameraDir);
	struct FVector GeneratePathToActor(class AActor* Goal, float WithinDistance, bool bAllowPartialPath);
	void InitNavigationHandle();
	void OverlappedActorEvent(class AActor* A);
	void TakeDamage(int DamageAmount, class AController* EventInstigator, const struct FVector& HitLocation, const struct FVector& Momentum, class UClass* DamageType, const struct FTraceHitInfo& HitInfo, class AActor* DamageCauser);
	void FireDeathEvent();
	void PlayDeath(const struct FVector& KillMomentum);
	void UpdateIntermediatePoint(class AActor* DestinationActor);
	bool CalcCamera(float fDeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot, float* out_FOV);
	bool IsIdle();
	void SetCurrentBehavior(class UGameCrowdAgentBehavior* BehaviorArchetype);
	void StopBehavior();
	void HandleBehaviorEvent(TEnumAsByte<ECrowdBehaviorEvent> EventType, class AActor* InInstigator, bool bViralCause, bool bPropagateViralFlag);
	void ActivateInstancedBehavior(class UGameCrowdAgentBehavior* NewBehaviorObject);
	void ActivateBehavior(class UGameCrowdAgentBehavior* NewBehaviorArchetype, class AActor* LookAtActor);
	void ResetSeePlayer();
	void TryRandomBehavior();
	void NotifySeePlayer(class APlayerController* PC);
	void PlaySpawnBehavior();
	void HandlePotentialAgentEncounter();
	void StopIdleAnimation();
	void PlayIdleAnimation();
	void OnPlayAgentAnimation(class USeqAct_PlayAgentAnimation* Action);
	void InitializeAgent(class AActor* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup, float AgentWarmupTime, bool bWarmupPosition, bool bCheckWarmupVisibility, TArray<struct FCrowdSpawnerPlayerInfo>* PlayerInfo);
	struct FVector GetAttemptedSpawnLocation(float Pct, const struct FVector& CurPos, float CurRadius, const struct FVector& DestPos, float DestRadius);
	void SetLighting(bool bEnableLightEnvironment, const struct FLightingChannelContainer& AgentLightingChannel, bool bCastShadows);
	void DisplayDebug(class AHUD* HUD, float* out_YL, float* out_YPos);
	void Destroyed();
	void ResetPooledAgent();
	void KillAgent();
	void PostBeginPlay();
	void SetMaxSpeed();
	void SetCurrentDestination(class AGameCrowdDestination* NewDest);
	void WaitForGroupMembers();
	bool PickBehaviorFrom(TArray<struct FBehaviorEntry> BehaviorList, const struct FVector& BestCameraLoc);
	bool IsPanicked();
	void FellOutOfWorld(class UClass* dmgType);
	struct FVector GetCollisionExtent();
};


// Class GameFramework.GameCrowdAgentSkeletal
// 0x0084 (0x04A0 - 0x041C)
class AGameCrowdAgentSkeletal : public AGameCrowdAgent
{
public:
	class USkeletalMeshComponent*                      SkeletalMeshComponent;                                    // 0x041C(0x0004) (CPF_Edit, CPF_ExportObject, CPF_Component, CPF_EditInline)
	class UAnimNodeBlend*                              SpeedBlendNode;                                           // 0x0420(0x0004)
	class UAnimNodeSlot*                               FullBodySlot;                                             // 0x0424(0x0004)
	class UAnimNodeSequence*                           ActionSeqNode;                                            // 0x0428(0x0004)
	class UAnimNodeSequence*                           WalkSeqNode;                                              // 0x042C(0x0004)
	class UAnimNodeSequence*                           RunSeqNode;                                               // 0x0430(0x0004)
	class UAnimTree*                                   AgentTree;                                                // 0x0434(0x0004)
	TArray<struct FName>                               WalkAnimNames;                                            // 0x0438(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<struct FName>                               RunAnimNames;                                             // 0x0444(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<struct FName>                               IdleAnimNames;                                            // 0x0450(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<struct FName>                               DeathAnimNames;                                           // 0x045C(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              SpeedBlendStart;                                          // 0x0468(0x0004) (CPF_Edit)
	float                                              SpeedBlendEnd;                                            // 0x046C(0x0004) (CPF_Edit)
	float                                              AnimVelRate;                                              // 0x0470(0x0004) (CPF_Edit)
	float                                              MaxSpeedBlendChangeSpeed;                                 // 0x0474(0x0004) (CPF_Edit)
	struct FName                                       MoveSyncGroupName;                                        // 0x0478(0x0008) (CPF_Edit)
	TArray<struct FGameCrowdAttachmentList>            Attachments;                                              // 0x0480(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              MaxTargetAcquireTime;                                     // 0x048C(0x0004) (CPF_Edit)
	unsigned long                                      bUseRootMotionVelocity : 1;                               // 0x0490(0x0004) (CPF_Edit)
	unsigned long                                      bAllowSkeletonUpdateChangeBasedOnTickResult : 1;          // 0x0490(0x0004) (CPF_Edit)
	unsigned long                                      bTickWhenNotVisible : 1;                                  // 0x0490(0x0004) (CPF_Edit)
	unsigned long                                      bIsPlayingIdleAnimation : 1;                              // 0x0490(0x0004)
	unsigned long                                      bIsPlayingDeathAnimation : 1;                             // 0x0490(0x0004)
	unsigned long                                      bIsPlayingImportantAnimation : 1;                         // 0x0490(0x0004)
	unsigned long                                      bAnimateThisTick : 1;                                     // 0x0490(0x0004)
	float                                              NotVisibleDisableTickTime;                                // 0x0494(0x0004) (CPF_Edit)
	float                                              MaxAnimationDistance;                                     // 0x0498(0x0004) (CPF_Edit)
	float                                              MaxAnimationDistanceSq;                                   // 0x049C(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdAgentSkeletal");
		return ptr;
	}


	void CreateAttachments();
	void OnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime);
	void StopIdleAnimation();
	void PlayIdleAnimation();
	void ClearLatentAnimation();
	void OnPlayAgentAnimation(class USeqAct_PlayAgentAnimation* Action);
	void SetRootMotion(bool bRootMotionEnabled);
	void PlayDeath(const struct FVector& KillMomentum);
	void SetLighting(bool bEnableLightEnvironment, const struct FLightingChannelContainer& AgentLightingChannel, bool bCastShadows);
	void PostBeginPlay();
};


// Class GameFramework.GameCrowdAgentSM
// 0x0008 (0x0424 - 0x041C)
class AGameCrowdAgentSM : public AGameCrowdAgent
{
public:
	class UStaticMeshComponent*                        Mesh;                                                     // 0x041C(0x0004) (CPF_Edit, CPF_ExportObject, CPF_Component, CPF_EditInline)
	class UMaterialInstanceConstant*                   MeshColor;                                                // 0x0420(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdAgentSM");
		return ptr;
	}


	void StopBehavior();
	void ActivateBehavior(class UGameCrowdAgentBehavior* NewBehaviorArchetype, class AActor* LookAtActor);
	void ChangeDebugColor(const struct FColor& InC);
	void InitDebugColor();
	void PostBeginPlay();
};


// Class GameFramework.GameCrowdAgentBehavior
// 0x0034 (0x0070 - 0x003C)
class UGameCrowdAgentBehavior : public UObject
{
public:
	TEnumAsByte<ECrowdBehaviorEvent>                   MyEventType;                                              // 0x003C(0x0001)
	TEnumAsByte<ECrowdBehaviorEvent>                   ViralBehaviorEvent;                                       // 0x003D(0x0001) (CPF_Edit)
	unsigned char                                      UnknownData00[0x2];                                       // 0x003E(0x0002) MISSED OFFSET
	float                                              DurationOfBehavior;                                       // 0x0040(0x0004) (CPF_Edit)
	float                                              TimeUntilStopBehavior;                                    // 0x0044(0x0004)
	unsigned long                                      bIdleBehavior : 1;                                        // 0x0048(0x0004) (CPF_Edit)
	unsigned long                                      bFaceActionTargetFirst : 1;                               // 0x0048(0x0004) (CPF_Edit)
	unsigned long                                      bIsViralBehavior : 1;                                     // 0x0048(0x0004) (CPF_Edit)
	unsigned long                                      bPassOnIsViralBehaviorFlag : 1;                           // 0x0048(0x0004) (CPF_Edit)
	class AActor*                                      ActionTarget;                                             // 0x004C(0x0004)
	float                                              MaxPlayerDistance;                                        // 0x0050(0x0004) (CPF_Edit)
	float                                              ViralRadius;                                              // 0x0054(0x0004) (CPF_Edit)
	float                                              DurationBeforeBecomesViral;                               // 0x0058(0x0004) (CPF_Edit)
	float                                              TimeToBecomeViral;                                        // 0x005C(0x0004) (CPF_Transient)
	float                                              DurationOfViralBehaviorPropagation;                       // 0x0060(0x0004) (CPF_Edit)
	float                                              TimeToStopPropagatingViralBehavior;                       // 0x0064(0x0004) (CPF_Transient)
	class AGameCrowdAgent*                             MyAgent;                                                  // 0x0068(0x0004)
	struct FColor                                      DebugBehaviorColor;                                       // 0x006C(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdAgentBehavior");
		return ptr;
	}


	bool AllowBehaviorAt(class AGameCrowdDestination* Destination);
	bool AllowThisDestination(class AGameCrowdDestination* Destination);
	void PropagateViralBehaviorTo(class AGameCrowdAgent* OtherAgent);
	class AActor* GetBehaviorInstigator();
	void ActivatedBy(class AActor* NewActionTarget);
	class AActor* GetDestinationActor();
	void ChangingDestination(class AGameCrowdDestination* NewDest);
	struct FString GetBehaviorString();
	void OnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime);
	void StopBehavior();
	void InitBehavior(class AGameCrowdAgent* Agent);
	bool HandleMovement();
	void FinishedTargetRotation();
	bool CanBeUsedBy(class AGameCrowdAgent* Agent, const struct FVector& CameraLoc);
	void Tick(float DeltaTime);
	bool ShouldEndIdle();
	class AGameCrowdBehaviorPoint* STATIC_TriggerCrowdBehavior(TEnumAsByte<ECrowdBehaviorEvent> EventType, class AActor* Instigator, const struct FVector& AtLocation, float InRange, float InDuration, class AActor* BaseActor, bool bRequireLOS);
};


// Class GameFramework.GameCrowdBehavior_PlayAnimation
// 0x002C (0x009C - 0x0070)
class UGameCrowdBehavior_PlayAnimation : public UGameCrowdAgentBehavior
{
public:
	TArray<struct FName>                               AnimationList;                                            // 0x0070(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              BlendInTime;                                              // 0x007C(0x0004) (CPF_Edit)
	float                                              BlendOutTime;                                             // 0x0080(0x0004) (CPF_Edit)
	unsigned long                                      bUseRootMotion : 1;                                       // 0x0084(0x0004) (CPF_Edit)
	unsigned long                                      bLookAtPlayer : 1;                                        // 0x0084(0x0004) (CPF_Edit)
	unsigned long                                      bLooping : 1;                                             // 0x0084(0x0004) (CPF_Edit)
	unsigned long                                      bBlendBetweenAnims : 1;                                   // 0x0084(0x0004) (CPF_Edit)
	class AActor*                                      CustomActionTarget;                                       // 0x0088(0x0004)
	int                                                LoopIndex;                                                // 0x008C(0x0004) (CPF_Edit)
	float                                              LoopTime;                                                 // 0x0090(0x0004) (CPF_Edit)
	class USeqAct_PlayAgentAnimation*                  AnimSequence;                                             // 0x0094(0x0004)
	int                                                AnimationIndex;                                           // 0x0098(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdBehavior_PlayAnimation");
		return ptr;
	}


	struct FString GetBehaviorString();
	void StopBehavior();
	void PlayAgentAnimationNow();
	void OnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime);
	void SetSequenceOutput();
	void FinishedTargetRotation();
	void InitBehavior(class AGameCrowdAgent* Agent);
};


// Class GameFramework.GameCrowdBehavior_RunFromPanic
// 0x0004 (0x0074 - 0x0070)
class UGameCrowdBehavior_RunFromPanic : public UGameCrowdAgentBehavior
{
public:
	class AActor*                                      PanicFocus;                                               // 0x0070(0x0004) (CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdBehavior_RunFromPanic");
		return ptr;
	}


	struct FString GetBehaviorString();
	bool AllowBehaviorAt(class AGameCrowdDestination* Destination);
	bool AllowThisDestination(class AGameCrowdDestination* Destination);
	class AActor* GetBehaviorInstigator();
	void StopBehavior();
	void InitBehavior(class AGameCrowdAgent* Agent);
	void ActivatedBy(class AActor* NewActionTarget);
};


// Class GameFramework.GameCrowdBehavior_WaitForGroup
// 0x0000 (0x0070 - 0x0070)
class UGameCrowdBehavior_WaitForGroup : public UGameCrowdAgentBehavior
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdBehavior_WaitForGroup");
		return ptr;
	}


	void StopBehavior();
	bool ShouldEndIdle();
	struct FString GetBehaviorString();
	void InitBehavior(class AGameCrowdAgent* Agent);
};


// Class GameFramework.GameCrowdBehavior_WaitInQueue
// 0x0008 (0x0078 - 0x0070)
class UGameCrowdBehavior_WaitInQueue : public UGameCrowdAgentBehavior
{
public:
	unsigned long                                      bStoppingBehavior : 1;                                    // 0x0070(0x0004)
	class AGameCrowdDestinationQueuePoint*             QueuePosition;                                            // 0x0074(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdBehavior_WaitInQueue");
		return ptr;
	}


	void StopBehavior();
	bool ShouldEndIdle();
	struct FString GetBehaviorString();
	class AActor* GetDestinationActor();
	void ChangingDestination(class AGameCrowdDestination* NewDest);
	bool HandleMovement();
};


// Class GameFramework.GameCrowdGroup
// 0x000C (0x0048 - 0x003C)
class UGameCrowdGroup : public UObject
{
public:
	TArray<class AGameCrowdAgent*>                     Members;                                                  // 0x003C(0x000C) (CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdGroup");
		return ptr;
	}


	void UpdateDestinations(class AGameCrowdDestination* NewDestination);
	void RemoveMember(class AGameCrowdAgent* Agent);
	void AddMember(class AGameCrowdAgent* Agent);
};


// Class GameFramework.GameCrowdInfoVolume
// 0x000C (0x0248 - 0x023C)
class AGameCrowdInfoVolume : public AVolume
{
public:
	TArray<class AGameCrowdDestination*>               PotentialSpawnPoints;                                     // 0x023C(0x000C) (CPF_Edit, CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdInfoVolume");
		return ptr;
	}


	void UnTouch(class AActor* Other);
	void Touch(class AActor* Other, class UPrimitiveComponent* OtherComp, const struct FVector& HitLocation, const struct FVector& HitNormal);
};


// Class GameFramework.GameCrowdInteractionPoint
// 0x0008 (0x0218 - 0x0210)
class AGameCrowdInteractionPoint : public AActor
{
public:
	unsigned long                                      bIsEnabled : 1;                                           // 0x0210(0x0004) (CPF_Edit, CPF_Net)
	class UCylinderComponent*                          CylinderComponent;                                        // 0x0214(0x0004) (CPF_Edit, CPF_ExportObject, CPF_Component, CPF_EditInline)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdInteractionPoint");
		return ptr;
	}


	void OnToggle(class USeqAct_Toggle* Action);
};


// Class GameFramework.GameCrowdBehaviorPoint
// 0x0014 (0x022C - 0x0218)
class AGameCrowdBehaviorPoint : public AGameCrowdInteractionPoint
{
public:
	float                                              RadiusOfBehaviorEvent;                                    // 0x0218(0x0004) (CPF_Config)
	float                                              DurationOfBehaviorEvent;                                  // 0x021C(0x0004) (CPF_Config)
	TEnumAsByte<ECrowdBehaviorEvent>                   EventType;                                                // 0x0220(0x0001) (CPF_Edit)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0221(0x0003) MISSED OFFSET
	unsigned long                                      bRequireLOS : 1;                                          // 0x0224(0x0004) (CPF_Edit)
	class AActor*                                      Initiator;                                                // 0x0228(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdBehaviorPoint");
		return ptr;
	}


	void Touch(class AActor* Other, class UPrimitiveComponent* OtherComp, const struct FVector& HitLocation, const struct FVector& HitNormal);
	void DestroySelf();
	void PostBeginPlay();
};


// Class GameFramework.GameCrowdDestination
// 0x0080 (0x0298 - 0x0218)
class AGameCrowdDestination : public AGameCrowdInteractionPoint
{
public:
	struct FPointer                                    VfTable_IEditorLinkSelectionInterface;                    // 0x0218(0x0004) (CPF_Const, CPF_Native, CPF_NoExport)
	unsigned long                                      bKillWhenReached : 1;                                     // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bAllowAsPreviousDestination : 1;                          // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bAvoidWhenPanicked : 1;                                   // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bSkipBehaviorIfPanicked : 1;                              // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bFleeDestination : 1;                                     // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bMustReachExactly : 1;                                    // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bHasRestrictions : 1;                                     // 0x021C(0x0004)
	unsigned long                                      bAllowsSpawning : 1;                                      // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bAllowCloudSpawning : 1;                                  // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bAllowVisibleSpawning : 1;                                // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bLineSpawner : 1;                                         // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bSpawnAtEdge : 1;                                         // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bSoftPerimeter : 1;                                       // 0x021C(0x0004) (CPF_Edit)
	unsigned long                                      bIsVisible : 1;                                           // 0x021C(0x0004)
	unsigned long                                      bWillBeVisible : 1;                                       // 0x021C(0x0004)
	unsigned long                                      bCanSpawnHereNow : 1;                                     // 0x021C(0x0004)
	unsigned long                                      bIsBeyondSpawnDistance : 1;                               // 0x021C(0x0004)
	unsigned long                                      bAdjacentToVisibleNode : 1;                               // 0x021C(0x0004)
	unsigned long                                      bHasNavigationMesh : 1;                                   // 0x021C(0x0004)
	TArray<class AGameCrowdDestination*>               NextDestinations;                                         // 0x0220(0x000C) (CPF_Edit, CPF_DuplicateTransient, CPF_NeedCtorLink)
	class AGameCrowdDestinationQueuePoint*             QueueHead;                                                // 0x022C(0x0004) (CPF_Edit, CPF_DuplicateTransient)
	int                                                Capacity;                                                 // 0x0230(0x0004) (CPF_Edit)
	float                                              Frequency;                                                // 0x0234(0x0004) (CPF_Edit)
	int                                                CustomerCount;                                            // 0x0238(0x0004)
	TArray<class UClass*>                              SupportedAgentClasses;                                    // 0x023C(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<class UObject*>                             SupportedArchetypes;                                      // 0x0248(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<class UClass*>                              RestrictedAgentClasses;                                   // 0x0254(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<class UObject*>                             RestrictedArchetypes;                                     // 0x0260(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              ExactReachTolerance;                                      // 0x026C(0x0004)
	struct FName                                       InteractionTag;                                           // 0x0270(0x0008) (CPF_Edit)
	float                                              InteractionDelay;                                         // 0x0278(0x0004) (CPF_Edit)
	TArray<struct FBehaviorEntry>                      ReachedBehaviors;                                         // 0x027C(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	class AGameCrowdAgent*                             AgentEnRoute;                                             // 0x0288(0x0004)
	float                                              Priority;                                                 // 0x028C(0x0004)
	float                                              LastSpawnTime;                                            // 0x0290(0x0004)
	class AGameCrowdPopulationManager*                 MyPopMgr;                                                 // 0x0294(0x0004) (CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdDestination");
		return ptr;
	}


	void DrawDebug(bool bPresistent, TArray<struct FCrowdSpawnerPlayerInfo>* PlayerInfo);
	float GetDestinationRadius();
	void PrioritizeSpawnPoint(float MaxSpawnDist, TArray<struct FCrowdSpawnerPlayerInfo>* PlayerInfo);
	bool AnalyzeSpawnPoint(float MaxSpawnDistSq, bool bForceNavMeshPathing, class UNavigationHandle* NavHandle, TArray<struct FCrowdSpawnerPlayerInfo>* PlayerInfo);
	void GetSpawnPosition(class USeqAct_GameCrowdSpawner* Spawner, struct FVector* SpawnPos, struct FRotator* SpawnRot);
	float GetSpawnRadius();
	bool AllowableDestinationFor(class AGameCrowdAgent* Agent);
	bool AtCapacity(unsigned char CheckCnt);
	void IncrementCustomerCount(class AGameCrowdAgent* ArrivingAgent);
	void DecrementCustomerCount(class AGameCrowdAgent* DepartingAgent);
	void PickNewDestinationFor(class AGameCrowdAgent* Agent, bool bIgnoreRestrictions);
	void ReachedDestination(class AGameCrowdAgent* Agent);
	void Destroyed();
	void PostBeginPlay();
	bool ReachedByAgent(class AGameCrowdAgent* Agent, const struct FVector& TestPosition, bool bTestExactly);
};


// Class GameFramework.GameCrowdDestinationQueuePoint
// 0x001C (0x0234 - 0x0218)
class AGameCrowdDestinationQueuePoint : public AGameCrowdInteractionPoint
{
public:
	class AGameCrowdDestinationQueuePoint*             NextQueuePosition;                                        // 0x0218(0x0004) (CPF_Edit)
	class AGameCrowdInteractionPoint*                  PreviousQueuePosition;                                    // 0x021C(0x0004)
	class AGameCrowdAgent*                             QueuedAgent;                                              // 0x0220(0x0004)
	class AGameCrowdDestination*                       QueueDestination;                                         // 0x0224(0x0004) (CPF_Transient)
	unsigned long                                      bClearingQueue : 1;                                       // 0x0228(0x0004)
	unsigned long                                      bPendingAdvance : 1;                                      // 0x0228(0x0004)
	float                                              AverageReactionTime;                                      // 0x022C(0x0004) (CPF_Edit)
	class UClass*                                      QueueBehaviorClass;                                       // 0x0230(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdDestinationQueuePoint");
		return ptr;
	}


	bool HasCustomer();
	void ClearQueue(class AGameCrowdAgent* OldCustomer);
	void AddCustomer(class AGameCrowdAgent* NewCustomer, class AGameCrowdInteractionPoint* PreviousPosition);
	void ActuallyAdvance();
	void AdvanceCustomerTo(class AGameCrowdInteractionPoint* FrontPosition);
	void ReachedDestination(class AGameCrowdAgent* Agent);
	bool HasSpace();
	bool QueueReachedBy(class AGameCrowdAgent* Agent, const struct FVector& TestPosition);
};


// Class GameFramework.GameCrowdPopulationManager
// 0x00C8 (0x02D8 - 0x0210)
class AGameCrowdPopulationManager : public ACrowdPopulationManagerBase
{
public:
	struct FPointer                                    VfTable_IInterface_NavigationHandle;                      // 0x0210(0x0004) (CPF_Const, CPF_Native, CPF_NoExport)
	struct FCrowdSpawnInfoItem                         CloudSpawnInfo;                                           // 0x0214(0x007C) (CPF_NeedCtorLink)
	TArray<struct FCrowdSpawnInfoItem>                 ScriptedSpawnInfo;                                        // 0x0290(0x000C) (CPF_NeedCtorLink)
	class AGameCrowdInfoVolume*                        ActiveCrowdInfoVolume;                                    // 0x029C(0x0004)
	TArray<class AGameCrowdDestination*>               GlobalPotentialSpawnPoints;                               // 0x02A0(0x000C) (CPF_NeedCtorLink)
	float                                              SplitScreenNumReduction;                                  // 0x02AC(0x0004)
	float                                              PlayerPositionPredictionTime;                             // 0x02B0(0x0004)
	float                                              HeadVisibilityOffset;                                     // 0x02B4(0x0004)
	class UClass*                                      NavigationHandleClass;                                    // 0x02B8(0x0004)
	class UNavigationHandle*                           NavigationHandle;                                         // 0x02BC(0x0004)
	class AGameCrowdAgent*                             QueryingAgent;                                            // 0x02C0(0x0004)
	TArray<struct FCrowdSpawnerPlayerInfo>             PlayerInfo;                                               // 0x02C4(0x000C) (CPF_NeedCtorLink)
	float                                              LastPlayerInfoUpdateTime;                                 // 0x02D0(0x0004)
	unsigned long                                      bDebugSpawns : 1;                                         // 0x02D4(0x0004) (CPF_Edit)
	unsigned long                                      bPauseCrowd : 1;                                          // 0x02D4(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdPopulationManager");
		return ptr;
	}


	class AGameCrowdAgent* CreateNewAgent(class AGameCrowdDestination* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup, struct FCrowdSpawnInfoItem* Item);
	bool Warmup(int WarmupNum, struct FCrowdSpawnInfoItem* Item);
	class AGameCrowdAgent* SpawnAgent(class AGameCrowdDestination* SpawnLoc, struct FCrowdSpawnInfoItem* Item);
	class AGameCrowdAgent* SpawnAgentByIdx(int SpawnerIdx, class AGameCrowdDestination* SpawnLoc);
	bool ValidateSpawnAt(class AGameCrowdDestination* Candidate, struct FCrowdSpawnInfoItem* Item);
	void AddPrioritizedSpawnPoint(class AGameCrowdDestination* GCD, struct FCrowdSpawnInfoItem* Item);
	void AnalyzeSpawnPoints(int StartIndex, int NumToUpdate, struct FCrowdSpawnInfoItem* Item);
	void PrioritizeSpawnPoints(float DeltaTime, struct FCrowdSpawnInfoItem* Item);
	bool STATIC_StaticGetPlayerInfo(TArray<struct FCrowdSpawnerPlayerInfo>* out_PlayerInfo);
	bool GetPlayerInfo();
	class AGameCrowdDestination* PickSpawnPoint(struct FCrowdSpawnInfoItem* Item);
	bool UpdateSpawner(float DeltaTime, struct FCrowdSpawnInfoItem* Item);
	void UpdateAllSpawners(float DeltaTime);
	void Tick(float DeltaTime);
	bool ShouldDebugDestinations();
	bool IsSpawningActive();
	void DisplayDebug(class AHUD* HUD, float* out_YL, float* out_YPos);
	void AgentDestroyed(class AGameCrowdAgent* Agent);
	void FlushAllAgents();
	void FlushAgents(const struct FCrowdSpawnInfoItem& Item);
	int CreateSpawner(class USeqAct_GameCrowdPopulationManagerToggle* inAction);
	void SetCrowdInfoVolume(class AGameCrowdInfoVolume* Vol);
	void RemoveSpawnPoint(class AGameCrowdDestination* GCD);
	void AddSpawnPoint(class AGameCrowdDestination* GCD);
	void NotifyPathChanged();
	void PostBeginPlay();
};


// Class GameFramework.GameCrowdReplicationActor
// 0x000C (0x021C - 0x0210)
class AGameCrowdReplicationActor : public AActor
{
public:
	class USeqAct_GameCrowdSpawner*                    Spawner;                                                  // 0x0210(0x0004) (CPF_Net)
	unsigned long                                      bSpawningActive : 1;                                      // 0x0214(0x0004) (CPF_Net)
	int                                                DestroyAllCount;                                          // 0x0218(0x0004) (CPF_Net)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdReplicationActor");
		return ptr;
	}


	void ReplicatedEvent(const struct FName& VarName);
};


// Class GameFramework.GameCrowdSpawnRelativeActor
// 0x0000 (0x0210 - 0x0210)
class AGameCrowdSpawnRelativeActor : public AActor
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdSpawnRelativeActor");
		return ptr;
	}

};


// Class GameFramework.GameDestinationConnRenderingComponent
// 0x0000 (0x01E8 - 0x01E8)
class UGameDestinationConnRenderingComponent : public UPrimitiveComponent
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameDestinationConnRenderingComponent");
		return ptr;
	}

};


// Class GameFramework.GameExplosion
// 0x00AC (0x00E8 - 0x003C)
class UGameExplosion : public UObject
{
public:
	unsigned long                                      bDirectionalExplosion : 1;                                // 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bIgnoreInstigator : 1;                                    // 0x003C(0x0004) (CPF_Transient)
	unsigned long                                      bAllowTeammateCringes : 1;                                // 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bFullDamageToAttachee : 1;                                // 0x003C(0x0004) (CPF_Transient)
	unsigned long                                      bAttachExplosionEmitterToAttachee : 1;                    // 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bPerformRadialBlurRelevanceCheck : 1;                     // 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bCausesFracture : 1;                                      // 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bAllowPerMaterialFX : 1;                                  // 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bParticleSystemIsBeingOverriddenDontUsePhysMatVersion : 1;// 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bSkipDefaultPhysMatParticleSystem : 1;                    // 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bUseMapSpecificValues : 1;                                // 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bUseOverlapCheck : 1;                                     // 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bOrientCameraShakeTowardsEpicenter : 1;                   // 0x003C(0x0004) (CPF_Edit)
	unsigned long                                      bAutoControllerVibration : 1;                             // 0x003C(0x0004) (CPF_Edit)
	float                                              DirectionalExplosionAngleDeg;                             // 0x0040(0x0004) (CPF_Edit)
	float                                              DamageDelay;                                              // 0x0044(0x0004) (CPF_Edit)
	float                                              Damage;                                                   // 0x0048(0x0004) (CPF_Edit)
	float                                              DamageRadius;                                             // 0x004C(0x0004) (CPF_Edit)
	float                                              DamageFalloffExponent;                                    // 0x0050(0x0004) (CPF_Edit)
	class AActor*                                      ActorToIgnoreForDamage;                                   // 0x0054(0x0004) (CPF_Transient)
	class UClass*                                      ActorClassToIgnoreForDamage;                              // 0x0058(0x0004) (CPF_Edit)
	class UClass*                                      ActorClassToIgnoreForKnockdownsAndCringes;                // 0x005C(0x0004) (CPF_Edit)
	class UClass*                                      MyDamageType;                                             // 0x0060(0x0004) (CPF_Edit)
	float                                              KnockDownRadius;                                          // 0x0064(0x0004) (CPF_Edit)
	float                                              KnockDownStrength;                                        // 0x0068(0x0004) (CPF_Edit)
	float                                              CringeRadius;                                             // 0x006C(0x0004) (CPF_Edit)
	struct FVector2D                                   CringeDuration;                                           // 0x0070(0x0008) (CPF_Edit)
	float                                              MomentumTransferScale;                                    // 0x0078(0x0004) (CPF_Edit)
	class UParticleSystem*                             ParticleEmitterTemplate;                                  // 0x007C(0x0004) (CPF_Edit)
	float                                              ExplosionEmitterScale;                                    // 0x0080(0x0004) (CPF_Edit)
	class AActor*                                      HitActor;                                                 // 0x0084(0x0004)
	struct FVector                                     HitLocation;                                              // 0x0088(0x000C)
	struct FVector                                     HitNormal;                                                // 0x0094(0x000C)
	class USoundCue*                                   ExplosionSound;                                           // 0x00A0(0x0004) (CPF_Edit)
	class USoundCue*                                   ExplosionSoundHurtSomeone;                                // 0x00A4(0x0004) (CPF_Edit)
	class UPointLightComponent*                        ExploLight;                                               // 0x00A8(0x0004) (CPF_Edit, CPF_ExportObject, CPF_Component, CPF_EditInline)
	float                                              ExploLightFadeOutTime;                                    // 0x00AC(0x0004) (CPF_Edit)
	class URadialBlurComponent*                        ExploRadialBlur;                                          // 0x00B0(0x0004) (CPF_Edit, CPF_ExportObject, CPF_Component, CPF_EditInline)
	float                                              ExploRadialBlurFadeOutTime;                               // 0x00B4(0x0004) (CPF_Edit)
	float                                              ExploRadialBlurMaxBlur;                                   // 0x00B8(0x0004) (CPF_Edit)
	float                                              FractureMeshRadius;                                       // 0x00BC(0x0004) (CPF_Edit)
	float                                              FracturePartVel;                                          // 0x00C0(0x0004) (CPF_Edit)
	class UCameraShake*                                CamShake;                                                 // 0x00C4(0x0004) (CPF_Edit, CPF_EditInline)
	class UCameraShake*                                CamShake_Left;                                            // 0x00C8(0x0004) (CPF_Edit, CPF_EditInline)
	class UCameraShake*                                CamShake_Right;                                           // 0x00CC(0x0004) (CPF_Edit, CPF_EditInline)
	class UCameraShake*                                CamShake_Rear;                                            // 0x00D0(0x0004) (CPF_Edit, CPF_EditInline)
	float                                              CamShakeInnerRadius;                                      // 0x00D4(0x0004) (CPF_Edit)
	float                                              CamShakeOuterRadius;                                      // 0x00D8(0x0004) (CPF_Edit)
	float                                              CamShakeFalloff;                                          // 0x00DC(0x0004) (CPF_Edit)
	class UClass*                                      CameraLensEffect;                                         // 0x00E0(0x0004) (CPF_Edit)
	float                                              CameraLensEffectRadius;                                   // 0x00E4(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameExplosion");
		return ptr;
	}

};


// Class GameFramework.GameExplosionActor
// 0x0058 (0x0268 - 0x0210)
class AGameExplosionActor : public AActor
{
public:
	unsigned long                                      bHasExploded : 1;                                         // 0x0210(0x0004) (CPF_Transient)
	unsigned long                                      bExplodeMoreThanOnce : 1;                                 // 0x0210(0x0004) (CPF_Edit)
	unsigned long                                      bTrackExplosionParticleSystemLifespan : 1;                // 0x0210(0x0004)
	unsigned long                                      bDrawDebug : 1;                                           // 0x0210(0x0004)
	class UPointLightComponent*                        ExplosionLight;                                           // 0x0214(0x0004) (CPF_ExportObject, CPF_Transient, CPF_Component, CPF_EditInline)
	class URadialBlurComponent*                        ExplosionRadialBlur;                                      // 0x0218(0x0004) (CPF_ExportObject, CPF_Transient, CPF_Component, CPF_EditInline)
	float                                              LightFadeTime;                                            // 0x021C(0x0004) (CPF_Transient)
	float                                              LightFadeTimeRemaining;                                   // 0x0220(0x0004) (CPF_Transient)
	float                                              LightInitialBrightness;                                   // 0x0224(0x0004) (CPF_Transient)
	float                                              RadialBlurFadeTime;                                       // 0x0228(0x0004) (CPF_Transient)
	float                                              RadialBlurFadeTimeRemaining;                              // 0x022C(0x0004) (CPF_Transient)
	float                                              RadialBlurMaxBlurAmount;                                  // 0x0230(0x0004) (CPF_Transient)
	class UGameExplosion*                              ExplosionTemplate;                                        // 0x0234(0x0004)
	class URB_RadialImpulseComponent*                  RadialImpulseComponent;                                   // 0x0238(0x0004) (CPF_ExportObject, CPF_Component, CPF_EditInline)
	class AController*                                 InstigatorController;                                     // 0x023C(0x0004)
	class AActor*                                      HitActorFromPhysMaterialTrace;                            // 0x0240(0x0004)
	struct FVector                                     HitLocationFromPhysMaterialTrace;                         // 0x0244(0x000C)
	class AActor*                                      Attachee;                                                 // 0x0250(0x0004)
	class AController*                                 AttacheeController;                                       // 0x0254(0x0004)
	float                                              DirectionalExplosionMinDot;                               // 0x0258(0x0004) (CPF_Transient)
	struct FVector                                     ExplosionDirection;                                       // 0x025C(0x000C) (CPF_Net, CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameExplosionActor");
		return ptr;
	}


	class UCameraShake* ChooseCameraShake(const struct FVector& Epicenter, class APlayerController* PC);
	void SpawnCameraLensEffects();
	void DoExplosionCameraEffects();
	void DrawDebug();
	void DelayedExplosionDamage();
	void Explode(class UGameExplosion* NewExplosionTemplate, const struct FVector& Direction);
	void SpawnExplosionFogVolume();
	void SpawnExplosionDecal();
	void SpawnExplosionParticleSystem(class UParticleSystem* Template);
	void UpdateExplosionTemplateWithPerMaterialFX(class UPhysicalMaterial* PhysMaterial);
	void SpecialCringeEffectsFor(class AActor* Victim, float VictimDist);
	void SpecialPawnEffectsFor(class AGamePawn* VictimPawn, float VictimDist);
	float GetEffectCheckRadius(bool bCauseDamage, bool bCauseFractureEffects, bool bCauseEffects);
	bool DoExplosionDamage(bool bCauseDamage, bool bCauseEffects);
	float STATIC_BoxDistanceToPoint(const struct FVector& Start, const struct FBox& BBox);
	bool IsBehindExplosion(class AActor* A);
	bool DoFullDamageToActor(class AActor* Victim);
	class UPhysicalMaterial* GetPhysicalMaterial();
	void PreBeginPlay();
};


// Class GameFramework.GamePawn
// 0x0004 (0x0498 - 0x0494)
class AGamePawn : public APawn
{
public:
	unsigned long                                      bLastHitWasHeadShot : 1;                                  // 0x0494(0x0004) (CPF_Net, CPF_Transient)
	unsigned long                                      bRespondToExplosions : 1;                                 // 0x0494(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GamePawn");
		return ptr;
	}


	void ReattachMeshWithoutBeingSeen();
	void ReattachMesh();
	void UpdateShadowSettings(bool bInWantShadow);
};


// Class GameFramework.DebugCameraController
// 0x0034 (0x0614 - 0x05E0)
class ADebugCameraController : public AGamePlayerController
{
public:
	struct FName                                       PrimaryKey;                                               // 0x05E0(0x0008) (CPF_Config, CPF_GlobalConfig)
	struct FName                                       SecondaryKey;                                             // 0x05E8(0x0008) (CPF_Config, CPF_GlobalConfig)
	struct FName                                       UnselectKey;                                              // 0x05F0(0x0008) (CPF_Config, CPF_GlobalConfig)
	unsigned long                                      bShowSelectedInfo : 1;                                    // 0x05F8(0x0004) (CPF_Config, CPF_GlobalConfig)
	unsigned long                                      bDrawDebugText : 1;                                       // 0x05F8(0x0004)
	unsigned long                                      bIsActive : 1;                                            // 0x05F8(0x0004)
	unsigned long                                      bIsFrozenRendering : 1;                                   // 0x05F8(0x0004)
	class UClass*                                      HUDClass;                                                 // 0x05FC(0x0004)
	class APlayerController*                           OriginalControllerRef;                                    // 0x0600(0x0004)
	class UPlayer*                                     OriginalPlayer;                                           // 0x0604(0x0004)
	class UDrawFrustumComponent*                       DrawFrustum;                                              // 0x0608(0x0004) (CPF_ExportObject, CPF_Component, CPF_EditInline)
	class AActor*                                      SelectedActor;                                            // 0x060C(0x0004)
	class UPrimitiveComponent*                         SelectedComponent;                                        // 0x0610(0x0004) (CPF_ExportObject, CPF_Component, CPF_EditInline)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.DebugCameraController");
		return ptr;
	}


	struct FString ConsoleCommand(const struct FString& Command, bool bWriteToLog);
	void ShowDebugSelectedInfo();
	bool NativeInputKey(int ControllerId, const struct FName& Key, TEnumAsByte<EInputEvent> Event, float AmountDepressed, bool bGamepad);
	void InitDebugInputSystem();
	void DisableDebugCamera();
	void NormalSpeed();
	void MoreSpeed();
	void SetFreezeRendering();
	void OnDeactivate(class APlayerController* PC);
	void OnActivate(class APlayerController* PC);
	void PostBeginPlay();
	void Unselect();
	void SecondarySelect(const struct FVector& HitLoc, const struct FVector& HitNormal, const struct FTraceHitInfo& HitInfo);
	void PrimarySelect(const struct FVector& HitLoc, const struct FVector& HitNormal, const struct FTraceHitInfo& HitInfo);
};


// Class GameFramework.MobileInputZone
// 0x01E4 (0x0220 - 0x003C)
class UMobileInputZone : public UObject
{
public:
	TEnumAsByte<EZoneType>                             Type;                                                     // 0x003C(0x0001) (CPF_Edit, CPF_Config)
	unsigned char                                      TouchpadIndex;                                            // 0x003D(0x0001) (CPF_Edit)
	TEnumAsByte<EZoneState>                            State;                                                    // 0x003E(0x0001)
	TEnumAsByte<EZoneSlideType>                        SlideType;                                                // 0x003F(0x0001) (CPF_Edit, CPF_Config)
	struct FString                                     Caption;                                                  // 0x0040(0x000C) (CPF_Edit, CPF_Config, CPF_NeedCtorLink)
	struct FName                                       InputKey;                                                 // 0x004C(0x0008) (CPF_Edit, CPF_Config)
	struct FName                                       HorizontalInputKey;                                       // 0x0054(0x0008) (CPF_Edit, CPF_Config)
	struct FName                                       TapInputKey;                                              // 0x005C(0x0008) (CPF_Edit, CPF_Config)
	struct FName                                       DoubleTapInputKey;                                        // 0x0064(0x0008) (CPF_Edit, CPF_Config)
	float                                              VertMultiplier;                                           // 0x006C(0x0004) (CPF_Edit, CPF_Config)
	float                                              HorizMultiplier;                                          // 0x0070(0x0004) (CPF_Edit, CPF_Config)
	float                                              Acceleration;                                             // 0x0074(0x0004) (CPF_Edit, CPF_Config)
	float                                              Smoothing;                                                // 0x0078(0x0004) (CPF_Edit, CPF_Config)
	float                                              EscapeVelocityStrength;                                   // 0x007C(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bScalePawnMovement : 1;                                   // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bRelativeX : 1;                                           // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bRelativeY : 1;                                           // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bRelativeSizeX : 1;                                       // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bRelativeSizeY : 1;                                       // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bActiveSizeYFromX : 1;                                    // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bSizeYFromSizeX : 1;                                      // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bApplyGlobalScaleToActiveSizes : 1;                       // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bCenterX : 1;                                             // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bCenterY : 1;                                             // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bIsInvisible : 1;                                         // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bQuickDoubleTap : 1;                                      // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bCenterOnEvent : 1;                                       // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bSliderHasTrack : 1;                                      // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bFloatingTiltZone : 1;                                    // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bUseGentleTransitions : 1;                                // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bAllowFirstDeltaForTrackballZone : 1;                     // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bRenderGuides : 1;                                        // 0x0080(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bIsDoubleTapAndHold : 1;                                  // 0x0080(0x0004)
	float                                              X;                                                        // 0x0084(0x0004) (CPF_Edit, CPF_Config)
	float                                              Y;                                                        // 0x0088(0x0004) (CPF_Edit, CPF_Config)
	float                                              SizeX;                                                    // 0x008C(0x0004) (CPF_Edit, CPF_Config)
	float                                              SizeY;                                                    // 0x0090(0x0004) (CPF_Edit, CPF_Config)
	float                                              ActiveSizeX;                                              // 0x0094(0x0004) (CPF_Edit, CPF_Config)
	float                                              ActiveSizeY;                                              // 0x0098(0x0004) (CPF_Edit, CPF_Config)
	float                                              InitialX;                                                 // 0x009C(0x0004) (CPF_Const)
	float                                              InitialY;                                                 // 0x00A0(0x0004) (CPF_Const)
	float                                              InitialSizeX;                                             // 0x00A4(0x0004) (CPF_Const)
	float                                              InitialSizeY;                                             // 0x00A8(0x0004) (CPF_Const)
	float                                              InitialActiveSizeX;                                       // 0x00AC(0x0004) (CPF_Const)
	float                                              InitialActiveSizeY;                                       // 0x00B0(0x0004) (CPF_Const)
	float                                              AuthoredGlobalScale;                                      // 0x00B4(0x0004) (CPF_Edit, CPF_Config)
	float                                              Border;                                                   // 0x00B8(0x0004) (CPF_Edit, CPF_Config)
	float                                              ResetCenterAfterInactivityTime;                           // 0x00BC(0x0004) (CPF_Edit, CPF_Config)
	float                                              TapDistanceConstraint;                                    // 0x00C0(0x0004) (CPF_Edit, CPF_Config)
	float                                              ActivateTime;                                             // 0x00C4(0x0004) (CPF_Edit, CPF_Config)
	float                                              DeactivateTime;                                           // 0x00C8(0x0004) (CPF_Edit, CPF_Config)
	struct FColor                                      RenderColor;                                              // 0x00CC(0x0004) (CPF_Edit, CPF_Config)
	float                                              InactiveAlpha;                                            // 0x00D0(0x0004) (CPF_Edit, CPF_Config)
	float                                              CaptionXAdjustment;                                       // 0x00D4(0x0004) (CPF_Edit, CPF_Config)
	float                                              CaptionYAdjustment;                                       // 0x00D8(0x0004) (CPF_Edit, CPF_Config)
	class UTexture2D*                                  OverrideTexture1;                                         // 0x00DC(0x0004) (CPF_Edit)
	struct FString                                     OverrideTexture1Name;                                     // 0x00E0(0x000C) (CPF_Config, CPF_NeedCtorLink)
	struct FTextureUVs                                 OverrideUVs1;                                             // 0x00EC(0x0010) (CPF_Edit, CPF_Config)
	class UTexture2D*                                  OverrideTexture2;                                         // 0x00FC(0x0004) (CPF_Edit)
	struct FString                                     OverrideTexture2Name;                                     // 0x0100(0x000C) (CPF_Config, CPF_NeedCtorLink)
	struct FTextureUVs                                 OverrideUVs2;                                             // 0x010C(0x0010) (CPF_Edit, CPF_Config)
	struct FVector2D                                   InitialLocation;                                          // 0x011C(0x0008)
	struct FVector2D                                   CurrentLocation;                                          // 0x0124(0x0008)
	struct FVector2D                                   CurrentCenter;                                            // 0x012C(0x0008)
	struct FVector2D                                   InitialCenter;                                            // 0x0134(0x0008)
	struct FVector2D                                   PreviousLocations[0x6];                                   // 0x013C(0x0008)
	float                                              PreviousMoveDeltaTimes[0x6];                              // 0x016C(0x0004)
	int                                                PreviousLocationCount;                                    // 0x0184(0x0004)
	float                                              LastTouchTime;                                            // 0x0188(0x0004)
	float                                              TimeSinceLastTapRepeat;                                   // 0x018C(0x0004)
	float                                              AnimatingFadeOpacity;                                     // 0x0190(0x0004)
	class UMobilePlayerInput*                          InputOwner;                                               // 0x0194(0x0004)
	float                                              TransitionTime;                                           // 0x0198(0x0004)
	struct FVector2D                                   EscapeVelocity;                                           // 0x019C(0x0008)
	TArray<class USeqEvent_MobileZoneBase*>            MobileSeqEventHandlers;                                   // 0x01A4(0x000C) (CPF_NeedCtorLink)
	struct FVector2D                                   LastAxisValues;                                           // 0x01B0(0x0008)
	float                                              TotalActiveTime;                                          // 0x01B8(0x0004)
	float                                              LastWentActiveTime;                                       // 0x01BC(0x0004)
	struct FScriptDelegate                             __OnProcessInputDelegate__Delegate;                       // 0x01C0(0x0010) (CPF_NeedCtorLink)
	struct FScriptDelegate                             __OnTapDelegate__Delegate;                                // 0x01D0(0x0010) (CPF_NeedCtorLink)
	struct FScriptDelegate                             __OnDoubleTapDelegate__Delegate;                          // 0x01E0(0x0010) (CPF_NeedCtorLink)
	struct FScriptDelegate                             __OnProcessSlide__Delegate;                               // 0x01F0(0x0010) (CPF_NeedCtorLink)
	struct FScriptDelegate                             __OnPreDrawZone__Delegate;                                // 0x0200(0x0010) (CPF_NeedCtorLink)
	struct FScriptDelegate                             __OnPostDrawZone__Delegate;                               // 0x0210(0x0010) (CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileInputZone");
		return ptr;
	}


	void AddKismetEventHandler(class USeqEvent_MobileZoneBase* NewHandler);
	void OnPostDrawZone(class UMobileInputZone* Zone, class UCanvas* Canvas);
	bool OnPreDrawZone(class UMobileInputZone* Zone, class UCanvas* Canvas);
	bool OnProcessSlide(class UMobileInputZone* Zone, TEnumAsByte<ETouchType> EventType, int SlideValue, const struct FVector2D& ViewportSize);
	bool OnDoubleTapDelegate(class UMobileInputZone* Zone, TEnumAsByte<ETouchType> EventType, const struct FVector2D& TouchLocation);
	bool OnTapDelegate(class UMobileInputZone* Zone, TEnumAsByte<ETouchType> EventType, const struct FVector2D& TouchLocation);
	bool OnProcessInputDelegate(class UMobileInputZone* Zone, float DeltaTime, int Handle, TEnumAsByte<ETouchType> EventType, const struct FVector2D& TouchLocation);
	void DeactivateZone();
	void ActivateZone();
};


// Class GameFramework.MobileHUD
// 0x00EC (0x0584 - 0x0498)
class AMobileHUD : public AHUD
{
public:
	unsigned long                                      bShowGameHud : 1;                                         // 0x0498(0x0004) (CPF_Config)
	unsigned long                                      bShowMobileHud : 1;                                       // 0x0498(0x0004) (CPF_Config)
	unsigned long                                      bForceMobileHUD : 1;                                      // 0x0498(0x0004) (CPF_Config, CPF_GlobalConfig)
	unsigned long                                      bShowMobileTilt : 1;                                      // 0x0498(0x0004) (CPF_Config)
	unsigned long                                      bDebugTouches : 1;                                        // 0x0498(0x0004) (CPF_Config)
	unsigned long                                      bDebugZones : 1;                                          // 0x0498(0x0004) (CPF_Config)
	unsigned long                                      bDebugZonePresses : 1;                                    // 0x0498(0x0004) (CPF_Config)
	unsigned long                                      bShowMotionDebug : 1;                                     // 0x0498(0x0004) (CPF_Config)
	class UTexture2D*                                  JoystickBackground;                                       // 0x049C(0x0004)
	struct FTextureUVs                                 JoystickBackgroundUVs;                                    // 0x04A0(0x0010)
	class UTexture2D*                                  JoystickHat;                                              // 0x04B0(0x0004)
	struct FTextureUVs                                 JoystickHatUVs;                                           // 0x04B4(0x0010)
	class UTexture2D*                                  ButtonImages[0x2];                                        // 0x04C4(0x0004)
	struct FTextureUVs                                 ButtonUVs[0x2];                                           // 0x04CC(0x0010)
	class UFont*                                       ButtonFont;                                               // 0x04EC(0x0004)
	struct FColor                                      ButtonCaptionColor;                                       // 0x04F0(0x0004)
	class UTexture2D*                                  TrackballBackground;                                      // 0x04F4(0x0004)
	struct FTextureUVs                                 TrackballBackgroundUVs;                                   // 0x04F8(0x0010)
	class UTexture2D*                                  TrackballTouchIndicator;                                  // 0x0508(0x0004)
	struct FTextureUVs                                 TrackballTouchIndicatorUVs;                               // 0x050C(0x0010)
	class UTexture2D*                                  SliderImages[0x4];                                        // 0x051C(0x0004)
	struct FTextureUVs                                 SliderUVs[0x4];                                           // 0x052C(0x0010)
	float                                              MobileTiltX;                                              // 0x056C(0x0004) (CPF_Config)
	float                                              MobileTiltY;                                              // 0x0570(0x0004) (CPF_Config)
	float                                              MobileTiltSize;                                           // 0x0574(0x0004) (CPF_Config)
	TArray<class USeqEvent_HudRender*>                 KismetRenderEvents;                                       // 0x0578(0x000C) (CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileHUD");
		return ptr;
	}


	void RenderKismetHud();
	void AddKismetRenderEvent(class USeqEvent_HudRender* NewEvent);
	void RefreshKismetLinks();
	void DrawMobileZone_Slider(class UMobileInputZone* Zone);
	void DrawMobileTilt(class UMobilePlayerInput* MobileInput);
	void DrawMobileZone_Trackball(class UMobileInputZone* Zone);
	void DrawMobileZone_Joystick(class UMobileInputZone* Zone);
	void DrawMobileZone_Button(class UMobileInputZone* Zone);
	void DrawInputZoneOverlays();
	void RenderMobileMenu();
	bool ShowMobileHud();
	void DrawMobileDebugString(float XPos, float YPos, const struct FString& Str);
	void PostRender();
	void PostBeginPlay();
};


// Class GameFramework.MobileMenuObject
// 0x0068 (0x00A4 - 0x003C)
class UMobileMenuObject : public UObject
{
public:
	unsigned long                                      bHasBeenInitialized : 1;                                  // 0x003C(0x0004) (CPF_Transient)
	unsigned long                                      bRelativeLeft : 1;                                        // 0x003C(0x0004)
	unsigned long                                      bRelativeTop : 1;                                         // 0x003C(0x0004)
	unsigned long                                      bRelativeWidth : 1;                                       // 0x003C(0x0004)
	unsigned long                                      bRelativeHeight : 1;                                      // 0x003C(0x0004)
	unsigned long                                      bApplyGlobalScaleLeft : 1;                                // 0x003C(0x0004)
	unsigned long                                      bApplyGlobalScaleTop : 1;                                 // 0x003C(0x0004)
	unsigned long                                      bApplyGlobalScaleWidth : 1;                               // 0x003C(0x0004)
	unsigned long                                      bApplyGlobalScaleHeight : 1;                              // 0x003C(0x0004)
	unsigned long                                      bHeightRelativeToWidth : 1;                               // 0x003C(0x0004)
	unsigned long                                      bXOffsetIsActual : 1;                                     // 0x003C(0x0004)
	unsigned long                                      bYOffsetIsActual : 1;                                     // 0x003C(0x0004)
	unsigned long                                      bIsActive : 1;                                            // 0x003C(0x0004)
	unsigned long                                      bIsHidden : 1;                                            // 0x003C(0x0004)
	unsigned long                                      bIsTouched : 1;                                           // 0x003C(0x0004)
	unsigned long                                      bIsHighlighted : 1;                                       // 0x003C(0x0004)
	unsigned long                                      bTellSceneBeforeRendering : 1;                            // 0x003C(0x0004)
	float                                              Left;                                                     // 0x0040(0x0004)
	float                                              Top;                                                      // 0x0044(0x0004)
	float                                              Width;                                                    // 0x0048(0x0004)
	float                                              Height;                                                   // 0x004C(0x0004)
	float                                              InitialLeft;                                              // 0x0050(0x0004)
	float                                              InitialTop;                                               // 0x0054(0x0004)
	float                                              InitialWidth;                                             // 0x0058(0x0004)
	float                                              InitialHeight;                                            // 0x005C(0x0004)
	float                                              AuthoredGlobalScale;                                      // 0x0060(0x0004) (CPF_Edit)
	float                                              TopLeeway;                                                // 0x0064(0x0004)
	float                                              BottomLeeway;                                             // 0x0068(0x0004)
	float                                              LeftLeeway;                                               // 0x006C(0x0004)
	float                                              RightLeeway;                                              // 0x0070(0x0004)
	float                                              XOffset;                                                  // 0x0074(0x0004)
	float                                              YOffset;                                                  // 0x0078(0x0004)
	struct FString                                     Tag;                                                      // 0x007C(0x000C) (CPF_NeedCtorLink)
	class UMobilePlayerInput*                          InputOwner;                                               // 0x0088(0x0004)
	float                                              Opacity;                                                  // 0x008C(0x0004)
	class UMobileMenuScene*                            OwnerScene;                                               // 0x0090(0x0004)
	struct FString                                     RelativeToTag;                                            // 0x0094(0x000C) (CPF_NeedCtorLink)
	class UMobileMenuObject*                           RelativeTo;                                               // 0x00A0(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuObject");
		return ptr;
	}


	void RenderObject(class UCanvas* Canvas, float DeltaTime);
	void SetCanvasPos(class UCanvas* Canvas, float OffsetX, float OffsetY);
	void InitMenuObject(class UMobilePlayerInput* PlayerInput, class UMobileMenuScene* Scene, int ScreenWidth, int ScreenHeight, bool bIsFirstInitialization);
	void GetRealPosition(float* PosX, float* PosY);
	bool OnTouch(TEnumAsByte<ETouchType> EventType, float TouchX, float TouchY, class UMobileMenuObject* ObjectOver, float DeltaTime);
};


// Class GameFramework.MobileMenuImage
// 0x002C (0x00D0 - 0x00A4)
class UMobileMenuImage : public UMobileMenuObject
{
public:
	class UTexture2D*                                  Image;                                                    // 0x00A4(0x0004)
	TEnumAsByte<EMenuImageDrawStyle>                   ImageDrawStyle;                                           // 0x00A8(0x0001)
	unsigned char                                      UnknownData00[0x3];                                       // 0x00A9(0x0003) MISSED OFFSET
	struct FUVCoords                                   ImageUVs;                                                 // 0x00AC(0x0014)
	struct FLinearColor                                ImageColor;                                               // 0x00C0(0x0010)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuImage");
		return ptr;
	}


	void RenderObject(class UCanvas* Canvas, float DeltaTime);
};


// Class GameFramework.MobileMenuScene
// 0x0058 (0x0094 - 0x003C)
class UMobileMenuScene : public UObject
{
public:
	struct FString                                     MenuName;                                                 // 0x003C(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<class UMobileMenuObject*>                   MenuObjects;                                              // 0x0048(0x000C) (CPF_Edit, CPF_ExportObject, CPF_NeedCtorLink, CPF_EditInline)
	class UFont*                                       SceneCaptionFont;                                         // 0x0054(0x0004) (CPF_Edit)
	class UMobilePlayerInput*                          InputOwner;                                               // 0x0058(0x0004) (CPF_Edit)
	unsigned long                                      bSceneDoesNotRequireInput : 1;                            // 0x005C(0x0004) (CPF_Edit)
	unsigned long                                      bRelativeLeft : 1;                                        // 0x005C(0x0004) (CPF_Edit)
	unsigned long                                      bRelativeTop : 1;                                         // 0x005C(0x0004) (CPF_Edit)
	unsigned long                                      bRelativeWidth : 1;                                       // 0x005C(0x0004) (CPF_Edit)
	unsigned long                                      bRelativeHeight : 1;                                      // 0x005C(0x0004) (CPF_Edit)
	unsigned long                                      bApplyGlobalScaleLeft : 1;                                // 0x005C(0x0004) (CPF_Edit)
	unsigned long                                      bApplyGlobalScaleTop : 1;                                 // 0x005C(0x0004) (CPF_Edit)
	unsigned long                                      bApplyGlobalScaleWidth : 1;                               // 0x005C(0x0004) (CPF_Edit)
	unsigned long                                      bApplyGlobalScaleHeight : 1;                              // 0x005C(0x0004) (CPF_Edit)
	unsigned char                                      TouchpadIndex;                                            // 0x0060(0x0001) (CPF_Edit)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0061(0x0003) MISSED OFFSET
	float                                              Left;                                                     // 0x0064(0x0004) (CPF_Edit)
	float                                              Top;                                                      // 0x0068(0x0004) (CPF_Edit)
	float                                              Width;                                                    // 0x006C(0x0004) (CPF_Edit)
	float                                              Height;                                                   // 0x0070(0x0004) (CPF_Edit)
	float                                              InitialLeft;                                              // 0x0074(0x0004)
	float                                              InitialTop;                                               // 0x0078(0x0004)
	float                                              InitialWidth;                                             // 0x007C(0x0004)
	float                                              InitialHeight;                                            // 0x0080(0x0004)
	float                                              AuthoredGlobalScale;                                      // 0x0084(0x0004) (CPF_Edit)
	float                                              Opacity;                                                  // 0x0088(0x0004) (CPF_Edit)
	class USoundCue*                                   UITouchSound;                                             // 0x008C(0x0004) (CPF_Edit)
	class USoundCue*                                   UIUnTouchSound;                                           // 0x0090(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuScene");
		return ptr;
	}


	bool MobileMenuCommand(const struct FString& Command);
	class UMobileMenuObject* FindMenuObject(const struct FString& Tag);
	void CleanUpScene();
	void Closed();
	bool Closing();
	void MadeTopMenu();
	void Opened(const struct FString& Mode);
	bool OnSceneTouch(TEnumAsByte<ETouchType> EventType, float TouchX, float TouchY, bool bInside);
	void OnTouch(class UMobileMenuObject* Sender, TEnumAsByte<ETouchType> EventType, float TouchX, float TouchY);
	void PreRenderMenuObject(class UMobileMenuObject* MenuObject, class UCanvas* Canvas, float RenderDelta);
	void RenderScene(class UCanvas* Canvas, float RenderDelta);
	class UFont* GetSceneFont();
	void InitMenuScene(class UMobilePlayerInput* PlayerInput, int ScreenWidth, int ScreenHeight, bool bIsFirstInitialization);
	float STATIC_GetGlobalScaleY();
	float STATIC_GetGlobalScaleX();
};


// Class GameFramework.MobilePlayerInput
// 0x0244 (0x04B4 - 0x0270)
class UMobilePlayerInput : public UPlayerInput
{
public:
	struct FTouchData                                  Touches[0x5];                                             // 0x0270(0x0048) (CPF_Edit, CPF_NeedCtorLink)
	class UMobileMenuObject*                           InteractiveObject;                                        // 0x03D8(0x0004)
	struct FDouble                                     InteractiveObjectLastTime;                                // 0x03DC(0x0008)
	TArray<struct FMobileInputGroup>                   MobileInputGroups;                                        // 0x03E4(0x000C) (CPF_Edit, CPF_NeedCtorLink, CPF_EditInline)
	int                                                CurrentMobileGroup;                                       // 0x03F0(0x0004) (CPF_Edit)
	TArray<class UMobileInputZone*>                    MobileInputZones;                                         // 0x03F4(0x000C) (CPF_Edit, CPF_NeedCtorLink, CPF_EditInline)
	TArray<struct FMobileInputZoneClassMap>            MobileInputZoneClasses;                                   // 0x0400(0x000C) (CPF_NeedCtorLink)
	float                                              MobilePitch;                                              // 0x040C(0x0004) (CPF_Edit)
	float                                              MobilePitchCenter;                                        // 0x0410(0x0004) (CPF_Edit)
	float                                              MobilePitchMultiplier;                                    // 0x0414(0x0004) (CPF_Edit)
	float                                              MobileYaw;                                                // 0x0418(0x0004) (CPF_Edit)
	float                                              MobileYawCenter;                                          // 0x041C(0x0004) (CPF_Edit)
	float                                              MobileYawMultiplier;                                      // 0x0420(0x0004) (CPF_Edit)
	float                                              MobilePitchDeadzoneSize;                                  // 0x0424(0x0004) (CPF_Edit, CPF_Config)
	float                                              MobileYawDeadzoneSize;                                    // 0x0428(0x0004) (CPF_Edit, CPF_Config)
	float                                              MobileDoubleTapTime;                                      // 0x042C(0x0004) (CPF_Edit, CPF_Config)
	float                                              MobileMinHoldForTap;                                      // 0x0430(0x0004) (CPF_Edit, CPF_Config)
	float                                              MobileTapRepeatTime;                                      // 0x0434(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bAllowTouchesInCinematic : 1;                             // 0x0438(0x0004) (CPF_Edit)
	unsigned long                                      bDisableTouchInput : 1;                                   // 0x0438(0x0004) (CPF_Edit)
	unsigned long                                      bAbsoluteTouchLocations : 1;                              // 0x0438(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bCollapseTouchInput : 1;                                  // 0x0438(0x0004) (CPF_Edit, CPF_Config)
	unsigned long                                      bFakeMobileTouches : 1;                                   // 0x0438(0x0004) (CPF_Edit)
	unsigned long                                      bDisableSceneRender : 1;                                  // 0x0438(0x0004) (CPF_Edit)
	float                                              ZoneTimeout;                                              // 0x043C(0x0004) (CPF_Edit, CPF_Config)
	TArray<class UMobileMenuScene*>                    MobileMenuStack;                                          // 0x0440(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	struct FString                                     NativeDebugString;                                        // 0x044C(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              MobileInactiveTime;                                       // 0x0458(0x0004) (CPF_Edit)
	TArray<class USeqEvent_MobileBase*>                MobileSeqEventHandlers;                                   // 0x045C(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TArray<class USeqEvent_MobileRawInput*>            MobileRawInputSeqEventHandlers;                           // 0x0468(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	struct FVector2D                                   MobileViewportOffset;                                     // 0x0474(0x0008)
	struct FVector2D                                   MobileViewportSize;                                       // 0x047C(0x0008)
	struct FScriptDelegate                             __OnTouchNotHandledInMenu__Delegate;                      // 0x0484(0x0010) (CPF_NeedCtorLink)
	struct FScriptDelegate                             __OnPreviewTouch__Delegate;                               // 0x0494(0x0010) (CPF_NeedCtorLink)
	struct FScriptDelegate                             __OnInputTouch__Delegate;                                 // 0x04A4(0x0010) (CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobilePlayerInput");
		return ptr;
	}


	class UMobileMenuScene* OpenMobileMenuMode(const struct FString& MenuClassName, const struct FString& Mode);
	class UMobileMenuScene* OpenMobileMenu(const struct FString& MenuClassName);
	void MobileMenuCommand(const struct FString& MenuCommand);
	void SceneRenderToggle();
	void PreClientTravel(const struct FString& PendingURL, TEnumAsByte<ETravelType> TravelType, bool bIsSeamlessTravel);
	void RenderMenus(class UCanvas* Canvas, float RenderDelta);
	void CloseAllMenus();
	void CloseMenuScene(class UMobileMenuScene* SceneToClose);
	class UMobileMenuScene* OpenMenuScene(class UClass* SceneClass, const struct FString& Mode);
	void SetMobileInputConfig(const struct FString& GroupName);
	void ActivateInputGroup(const struct FString& GroupName);
	TArray<class UMobileInputZone*> GetCurrentZones();
	bool HasZones();
	class UMobileInputZone* FindorAddZone(const struct FString& ZoneName);
	class UMobileInputZone* FindZone(const struct FString& ZoneName);
	void AddKismetRawInputEventHandler(class USeqEvent_MobileRawInput* NewHandler);
	void AddKismetEventHandler(class USeqEvent_MobileBase* NewHandler);
	void RefreshKismetLinks();
	void SwapZoneOwners();
	void InitializeInputZones();
	void InitTouchSystem();
	void ClientInitInputSystem();
	void InitInputSystem();
	bool ProcessWorldTouch(class UMobileInputZone* Zone, TEnumAsByte<ETouchType> EventType, const struct FVector2D& TouchLocation);
	void SendInputAxis(const struct FName& Key, float Delta, float DeltaTime);
	void SendInputKey(const struct FName& Key, TEnumAsByte<EInputEvent> Event, float AmountDepressed);
	void ConditionalUpdateInputZones(int NewViewportX, int NewViewportY, int NewViewportSizeX, int NewViewportSizeY);
	void NativeInitializeInputZones(bool bIsFirstInitialize);
	void NativeInitializeInputSystem();
	void OnInputTouch(int Handle, TEnumAsByte<ETouchType> Type, const struct FVector2D& TouchLocation, float DeviceTimestamp, int TouchpadIndex);
	bool OnPreviewTouch(float X, float Y, int TouchpadIndex);
	void OnTouchNotHandledInMenu();
	void PlayerInput(float DeltaTime);
	void CancelMobileInput();
	void ProcessMobileInput(float DeltaTime);
};


// Class GameFramework.NavMeshGoal_OutOfViewFrom
// 0x0014 (0x0068 - 0x0054)
class UNavMeshGoal_OutOfViewFrom : public UNavMeshPathGoalEvaluator
{
public:
	struct FPointer                                    GoalPoly;                                                 // 0x0054(0x0004) (CPF_Native)
	struct FVector                                     OutOfViewLocation;                                        // 0x0058(0x000C)
	unsigned long                                      bShowDebug : 1;                                           // 0x0064(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.NavMeshGoal_OutOfViewFrom");
		return ptr;
	}


	void Recycle();
	bool STATIC_MustBeHiddenFromThisPoint(class UNavigationHandle* NavHandle, const struct FVector& InOutOfViewLocation);
	void RecycleNative();
};


// Class GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations
// 0x0028 (0x0078 - 0x0050)
class UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations : public UNavMeshPathConstraint
{
public:
	struct FVector                                     Location;                                                 // 0x0050(0x000C) (CPF_Transient)
	struct FVector                                     Rotation;                                                 // 0x005C(0x000C) (CPF_Transient)
	float                                              DistanceToCheck;                                          // 0x0068(0x0004) (CPF_Transient)
	TArray<struct FVector>                             LocationsToCheck;                                         // 0x006C(0x000C) (CPF_Transient, CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations");
		return ptr;
	}


	void Recycle();
	bool STATIC_BiasAgainstPolysWithinDistanceOfLocations(class UNavigationHandle* NavHandle, const struct FVector& InLocation, const struct FRotator& InRotation, float InDistanceToCheck, TArray<struct FVector> InLocationsToCheck);
};


// Class GameFramework.SecondaryViewportClient
// 0x0000 (0x0040 - 0x0040)
class USecondaryViewportClient : public UScriptViewportClient
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SecondaryViewportClient");
		return ptr;
	}


	void PostRender(class UCanvas* Canvas);
};


// Class GameFramework.MobileSecondaryViewportClient
// 0x0000 (0x0040 - 0x0040)
class UMobileSecondaryViewportClient : public USecondaryViewportClient
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileSecondaryViewportClient");
		return ptr;
	}


	void PostRender(class UCanvas* Canvas);
};


// Class GameFramework.SeqAct_ControlGameMovie
// 0x0014 (0x0124 - 0x0110)
class USeqAct_ControlGameMovie : public USeqAct_Latent
{
public:
	struct FString                                     MovieName;                                                // 0x0110(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	int                                                StartOfRenderingMovieFrame;                               // 0x011C(0x0004) (CPF_Edit)
	int                                                EndOfRenderingMovieFrame;                                 // 0x0120(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_ControlGameMovie");
		return ptr;
	}

};


// Class GameFramework.SeqAct_Deproject
// 0x0028 (0x0124 - 0x00FC)
class USeqAct_Deproject : public USequenceAction
{
public:
	float                                              ScreenX;                                                  // 0x00FC(0x0004) (CPF_Edit)
	float                                              ScreenY;                                                  // 0x0100(0x0004) (CPF_Edit)
	float                                              TraceDistance;                                            // 0x0104(0x0004) (CPF_Edit)
	class UObject*                                     HitObject;                                                // 0x0108(0x0004)
	struct FVector                                     HitLocation;                                              // 0x010C(0x000C)
	struct FVector                                     HitNormal;                                                // 0x0118(0x000C)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_Deproject");
		return ptr;
	}

};


// Class GameFramework.SeqAct_GameCrowdPopulationManagerToggle
// 0x0040 (0x013C - 0x00FC)
class USeqAct_GameCrowdPopulationManagerToggle : public USequenceAction
{
public:
	float                                              WarmupPopulationPct;                                      // 0x00FC(0x0004) (CPF_Edit)
	class UGameCrowd_ListOfAgents*                     CrowdAgentList;                                           // 0x0100(0x0004) (CPF_Edit)
	unsigned long                                      bClearOldArchetypes : 1;                                  // 0x0104(0x0004) (CPF_Edit)
	unsigned long                                      bEnableCrowdLightEnvironment : 1;                         // 0x0104(0x0004) (CPF_Edit)
	unsigned long                                      bCastShadows : 1;                                         // 0x0104(0x0004) (CPF_Edit)
	unsigned long                                      bFillPotentialSpawnPoints : 1;                            // 0x0104(0x0004)
	unsigned long                                      bForceObstacleChecking : 1;                               // 0x0104(0x0004) (CPF_Edit)
	unsigned long                                      bForceNavMeshPathing : 1;                                 // 0x0104(0x0004) (CPF_Edit)
	unsigned long                                      bIndividualSpawner : 1;                                   // 0x0104(0x0004)
	int                                                MaxAgents;                                                // 0x0108(0x0004) (CPF_Edit)
	float                                              SpawnRate;                                                // 0x010C(0x0004) (CPF_Edit)
	struct FLightingChannelContainer                   AgentLightingChannel;                                     // 0x0110(0x0004)
	float                                              MaxSpawnDist;                                             // 0x0114(0x0004) (CPF_Edit)
	float                                              MinBehindSpawnDist;                                       // 0x0118(0x0004)
	TArray<class AGameCrowdDestination*>               PotentialSpawnPoints;                                     // 0x011C(0x000C) (CPF_NeedCtorLink)
	float                                              AgentWarmupTime;                                          // 0x0128(0x0004)
	int                                                NumAgentsToTickPerFrame;                                  // 0x012C(0x0004) (CPF_Edit)
	TArray<class AGameCrowdAgent*>                     LastSpawnedList;                                          // 0x0130(0x000C) (CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_GameCrowdPopulationManagerToggle");
		return ptr;
	}


	void AgentDestroyed(class AGameCrowdAgent* Agent);
	float GetMaxSpawnDist();
	void FillCrowdSpawnInfoItem(class AGameCrowdPopulationManager* PopMgr, struct FCrowdSpawnInfoItem* out_Item);
	int STATIC_GetObjClassVersion();
};


// Class GameFramework.SeqAct_GameCrowdSpawner
// 0x0000 (0x013C - 0x013C)
class USeqAct_GameCrowdSpawner : public USeqAct_GameCrowdPopulationManagerToggle
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_GameCrowdSpawner");
		return ptr;
	}


	int STATIC_GetObjClassVersion();
};


// Class GameFramework.SeqAct_MobileAddInputZones
// 0x000C (0x0108 - 0x00FC)
class USeqAct_MobileAddInputZones : public USequenceAction
{
public:
	struct FName                                       ZoneName;                                                 // 0x00FC(0x0008) (CPF_Edit)
	class UMobileInputZone*                            NewZone;                                                  // 0x0104(0x0004) (CPF_Edit, CPF_EditInline)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_MobileAddInputZones");
		return ptr;
	}

};


// Class GameFramework.SeqAct_MobileClearInputZones
// 0x0000 (0x00FC - 0x00FC)
class USeqAct_MobileClearInputZones : public USequenceAction
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_MobileClearInputZones");
		return ptr;
	}

};


// Class GameFramework.SeqAct_MobileRemoveInputZone
// 0x000C (0x0108 - 0x00FC)
class USeqAct_MobileRemoveInputZone : public USequenceAction
{
public:
	struct FString                                     ZoneName;                                                 // 0x00FC(0x000C) (CPF_Edit, CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_MobileRemoveInputZone");
		return ptr;
	}

};


// Class GameFramework.SeqAct_MobileSaveLoadValue
// 0x0000 (0x00FC - 0x00FC)
class USeqAct_MobileSaveLoadValue : public USequenceAction
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_MobileSaveLoadValue");
		return ptr;
	}


	int STATIC_GetObjClassVersion();
};


// Class GameFramework.SeqAct_ModifyProperty
// 0x000C (0x0108 - 0x00FC)
class USeqAct_ModifyProperty : public USequenceAction
{
public:
	TArray<struct FPropertyInfo>                       Properties;                                               // 0x00FC(0x000C) (CPF_Edit, CPF_NeedCtorLink, CPF_EditInline)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_ModifyProperty");
		return ptr;
	}

};


// Class GameFramework.SeqAct_PlayAgentAnimation
// 0x0024 (0x0134 - 0x0110)
class USeqAct_PlayAgentAnimation : public USeqAct_Latent
{
public:
	TArray<struct FName>                               AnimationList;                                            // 0x0110(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              BlendInTime;                                              // 0x011C(0x0004) (CPF_Edit)
	float                                              BlendOutTime;                                             // 0x0120(0x0004) (CPF_Edit)
	unsigned long                                      bUseRootMotion : 1;                                       // 0x0124(0x0004) (CPF_Edit)
	unsigned long                                      bFaceActionTargetFirst : 1;                               // 0x0124(0x0004) (CPF_Edit)
	unsigned long                                      bLooping : 1;                                             // 0x0124(0x0004) (CPF_Edit)
	unsigned long                                      bBlendBetweenAnims : 1;                                   // 0x0124(0x0004) (CPF_Edit)
	int                                                LoopIndex;                                                // 0x0128(0x0004) (CPF_Edit)
	float                                              LoopTime;                                                 // 0x012C(0x0004) (CPF_Edit)
	class AActor*                                      ActionTarget;                                             // 0x0130(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_PlayAgentAnimation");
		return ptr;
	}


	void SetCurrentAnimationActionFor(class AGameCrowdAgentSkeletal* Agent);
	int STATIC_GetObjClassVersion();
};


// Class GameFramework.SeqEvent_CrowdAgentReachedDestination
// 0x0000 (0x0114 - 0x0114)
class USeqEvent_CrowdAgentReachedDestination : public USequenceEvent
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_CrowdAgentReachedDestination");
		return ptr;
	}

};


// Class GameFramework.SeqEvent_HudRender
// 0x0014 (0x0128 - 0x0114)
class USeqEvent_HudRender : public USequenceEvent
{
public:
	TArray<class UObject*>                             Targets;                                                  // 0x0114(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	unsigned long                                      bIsActive : 1;                                            // 0x0120(0x0004) (CPF_Edit)
	float                                              AuthoredGlobalScale;                                      // 0x0124(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_HudRender");
		return ptr;
	}


	void Render(class UCanvas* TargetCanvas, class AHUD* TargetHud);
	void RegisterEvent();
};


// Class GameFramework.SeqEvent_MobileBase
// 0x0000 (0x0114 - 0x0114)
class USeqEvent_MobileBase : public USequenceEvent
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_MobileBase");
		return ptr;
	}


	void AddToMobileInput(class UMobilePlayerInput* MPI);
	void RegisterEvent();
};


// Class GameFramework.SeqEvent_MobileMotion
// 0x0018 (0x012C - 0x0114)
class USeqEvent_MobileMotion : public USeqEvent_MobileBase
{
public:
	float                                              Roll;                                                     // 0x0114(0x0004)
	float                                              Pitch;                                                    // 0x0118(0x0004)
	float                                              Yaw;                                                      // 0x011C(0x0004)
	float                                              DeltaRoll;                                                // 0x0120(0x0004)
	float                                              DeltaPitch;                                               // 0x0124(0x0004)
	float                                              DeltaYaw;                                                 // 0x0128(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_MobileMotion");
		return ptr;
	}


	int STATIC_GetObjClassVersion();
};


// Class GameFramework.SeqEvent_MobileZoneBase
// 0x000C (0x0120 - 0x0114)
class USeqEvent_MobileZoneBase : public USeqEvent_MobileBase
{
public:
	struct FString                                     TargetZoneName;                                           // 0x0114(0x000C) (CPF_Edit, CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_MobileZoneBase");
		return ptr;
	}


	void AddToMobileInput(class UMobilePlayerInput* MPI);
};


// Class GameFramework.SeqEvent_MobileButton
// 0x0004 (0x0124 - 0x0120)
class USeqEvent_MobileButton : public USeqEvent_MobileZoneBase
{
public:
	unsigned long                                      bWasActiveLastFrame : 1;                                  // 0x0120(0x0004)
	unsigned long                                      bSendPressedOnlyOnTouchDown : 1;                          // 0x0120(0x0004) (CPF_Edit)
	unsigned long                                      bSendPressedOnlyOnTouchUp : 1;                            // 0x0120(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_MobileButton");
		return ptr;
	}

};


// Class GameFramework.SeqEvent_MobileInput
// 0x0018 (0x0138 - 0x0120)
class USeqEvent_MobileInput : public USeqEvent_MobileZoneBase
{
public:
	float                                              XAxisValue;                                               // 0x0120(0x0004)
	float                                              YAxisValue;                                               // 0x0124(0x0004)
	float                                              CenterX;                                                  // 0x0128(0x0004)
	float                                              CenterY;                                                  // 0x012C(0x0004)
	float                                              CurrentX;                                                 // 0x0130(0x0004)
	float                                              CurrentY;                                                 // 0x0134(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_MobileInput");
		return ptr;
	}

};


// Class GameFramework.SeqEvent_MobileLook
// 0x0014 (0x0134 - 0x0120)
class USeqEvent_MobileLook : public USeqEvent_MobileZoneBase
{
public:
	float                                              Yaw;                                                      // 0x0120(0x0004)
	float                                              StickStrength;                                            // 0x0124(0x0004)
	struct FVector                                     RotationVector;                                           // 0x0128(0x000C)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_MobileLook");
		return ptr;
	}

};


// Class GameFramework.SeqEvent_MobileRawInput
// 0x0014 (0x0128 - 0x0114)
class USeqEvent_MobileRawInput : public USequenceEvent
{
public:
	int                                                TouchIndex;                                               // 0x0114(0x0004) (CPF_Edit)
	int                                                TouchpadIndex;                                            // 0x0118(0x0004) (CPF_Edit)
	float                                              TouchLocationX;                                           // 0x011C(0x0004)
	float                                              TouchLocationY;                                           // 0x0120(0x0004)
	float                                              TimeStamp;                                                // 0x0124(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_MobileRawInput");
		return ptr;
	}


	void RegisterEvent();
};


// Class GameFramework.SeqEvent_MobileObjectPicker
// 0x0030 (0x0158 - 0x0128)
class USeqEvent_MobileObjectPicker : public USeqEvent_MobileRawInput
{
public:
	float                                              TraceDistance;                                            // 0x0128(0x0004) (CPF_Edit)
	unsigned long                                      bCheckonTouch : 1;                                        // 0x012C(0x0004) (CPF_Edit)
	struct FVector                                     FinalTouchLocation;                                       // 0x0130(0x000C)
	struct FVector                                     FinalTouchNormal;                                         // 0x013C(0x000C)
	class UObject*                                     FinalTouchObject;                                         // 0x0148(0x0004)
	TArray<class UObject*>                             Targets;                                                  // 0x014C(0x000C) (CPF_Edit, CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_MobileObjectPicker");
		return ptr;
	}

};


// Class GameFramework.SeqEvent_MobileSwipe
// 0x0020 (0x0148 - 0x0128)
class USeqEvent_MobileSwipe : public USeqEvent_MobileRawInput
{
public:
	float                                              Tolerance;                                                // 0x0128(0x0004) (CPF_Edit)
	float                                              MinDistance;                                              // 0x012C(0x0004) (CPF_Edit)
	struct FVector2D                                   InitialTouch;                                             // 0x0130(0x0008)
	TArray<class AActor*>                              TouchedActors;                                            // 0x0138(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	float                                              TraceDistance;                                            // 0x0144(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_MobileSwipe");
		return ptr;
	}

};


// Class GameFramework.GameSkelCtrl_Recoil
// 0x007C (0x0138 - 0x00BC)
class UGameSkelCtrl_Recoil : public USkelControlBase
{
public:
	unsigned long                                      bBoneSpaceRecoil : 1;                                     // 0x00BC(0x0004) (CPF_Edit)
	unsigned long                                      bPlayRecoil : 1;                                          // 0x00BC(0x0004) (CPF_Edit, CPF_Transient)
	unsigned long                                      bOldPlayRecoil : 1;                                       // 0x00BC(0x0004) (CPF_Transient)
	unsigned long                                      bApplyControl : 1;                                        // 0x00BC(0x0004) (CPF_Transient)
	struct FRecoilDef                                  Recoil;                                                   // 0x00C0(0x0070) (CPF_Edit)
	struct FVector2D                                   Aim;                                                      // 0x0130(0x0008) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameSkelCtrl_Recoil");
		return ptr;
	}

};


// Class GameFramework.GameCameraBase
// 0x0008 (0x0044 - 0x003C)
class UGameCameraBase : public UObject
{
public:
	class AGamePlayerCamera*                           PlayerCamera;                                             // 0x003C(0x0004) (CPF_Transient)
	unsigned long                                      bResetCameraInterpolation : 1;                            // 0x0040(0x0004) (CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCameraBase");
		return ptr;
	}


	void ModifyPostProcessSettings(struct FPostProcessSettings* PP);
	void Init();
	void DisplayDebug(class AHUD* HUD, float* out_YL, float* out_YPos);
	void ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator* out_ViewRotation, struct FRotator* out_DeltaRot);
	void UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget* OutVT);
	void ResetInterpolation();
	void OnBecomeInActive(class UGameCameraBase* NewCamera);
	void OnBecomeActive(class UGameCameraBase* OldCamera);
};


// Class GameFramework.GameThirdPersonCamera
// 0x0154 (0x0198 - 0x0044)
class UGameThirdPersonCamera : public UGameCameraBase
{
public:
	float                                              WorstLocBlockedPct;                                       // 0x0044(0x0004)
	float                                              WorstLocPenetrationExtentScale;                           // 0x0048(0x0004) (CPF_Edit)
	float                                              PenetrationBlendOutTime;                                  // 0x004C(0x0004) (CPF_Edit)
	float                                              PenetrationBlendInTime;                                   // 0x0050(0x0004) (CPF_Edit)
	float                                              PenetrationBlockedPct;                                    // 0x0054(0x0004)
	float                                              PenetrationExtentScale;                                   // 0x0058(0x0004) (CPF_Edit)
	struct FVector                                     LastActualOriginOffset;                                   // 0x005C(0x000C) (CPF_Transient)
	struct FVector                                     LastActualCameraOrigin;                                   // 0x0068(0x000C) (CPF_Transient)
	struct FRotator                                    LastActualCameraOriginRot;                                // 0x0074(0x000C) (CPF_Transient)
	float                                              OriginOffsetInterpSpeed;                                  // 0x0080(0x0004) (CPF_Edit)
	struct FVector                                     LastViewOffset;                                           // 0x0084(0x000C) (CPF_Transient)
	float                                              LastCamFOV;                                               // 0x0090(0x0004) (CPF_Transient)
	struct FVector                                     LastIdealCameraOrigin;                                    // 0x0094(0x000C) (CPF_Transient)
	struct FRotator                                    LastIdealCameraOriginRot;                                 // 0x00A0(0x000C) (CPF_Transient)
	class UGameThirdPersonCameraMode*                  ThirdPersonCamDefault;                                    // 0x00AC(0x0004) (CPF_Edit, CPF_EditInline)
	class UClass*                                      ThirdPersonCamDefaultClass;                               // 0x00B0(0x0004) (CPF_Edit)
	class UGameThirdPersonCameraMode*                  CurrentCamMode;                                           // 0x00B4(0x0004) (CPF_Edit, CPF_Transient, CPF_EditInline)
	float                                              LastHeightAdjustment;                                     // 0x00B8(0x0004) (CPF_Transient)
	float                                              LastPitchAdjustment;                                      // 0x00BC(0x0004) (CPF_Transient)
	float                                              LastYawAdjustment;                                        // 0x00C0(0x0004) (CPF_Transient)
	float                                              LeftoverPitchAdjustment;                                  // 0x00C4(0x0004) (CPF_Transient)
	float                                              Focus_BackOffStrength;                                    // 0x00C8(0x0004) (CPF_Edit)
	float                                              Focus_StepHeightAdjustment;                               // 0x00CC(0x0004) (CPF_Edit)
	int                                                Focus_MaxTries;                                           // 0x00D0(0x0004) (CPF_Edit)
	float                                              Focus_FastAdjustKickInTime;                               // 0x00D4(0x0004) (CPF_Edit)
	float                                              LastFocusChangeTime;                                      // 0x00D8(0x0004) (CPF_Transient)
	struct FVector                                     ActualFocusPointWorldLoc;                                 // 0x00DC(0x000C) (CPF_Transient)
	struct FVector                                     LastFocusPointLoc;                                        // 0x00E8(0x000C) (CPF_Transient)
	struct FCamFocusPointParams                        FocusPoint;                                               // 0x00F4(0x0034) (CPF_Edit)
	unsigned long                                      bFocusPointSet : 1;                                       // 0x0128(0x0004)
	unsigned long                                      bFocusPointSuccessful : 1;                                // 0x0128(0x0004) (CPF_Transient)
	unsigned long                                      bDoingACameraTurn : 1;                                    // 0x0128(0x0004)
	unsigned long                                      bTurnAlignTargetWhenFinished : 1;                         // 0x0128(0x0004)
	unsigned long                                      bDrawDebug : 1;                                           // 0x0128(0x0004) (CPF_Edit)
	unsigned long                                      bDoingDirectLook : 1;                                     // 0x0128(0x0004) (CPF_Transient)
	unsigned long                                      bDebugChangedCameraMode : 1;                              // 0x0128(0x0004) (CPF_Edit)
	unsigned long                                      bDoSeamlessPivotTransition : 1;                           // 0x0128(0x0004) (CPF_Transient)
	float                                              TurnCurTime;                                              // 0x012C(0x0004)
	int                                                TurnStartAngle;                                           // 0x0130(0x0004)
	int                                                TurnEndAngle;                                             // 0x0134(0x0004)
	float                                              TurnTotalTime;                                            // 0x0138(0x0004)
	float                                              TurnDelay;                                                // 0x013C(0x0004)
	int                                                LastPostCamTurnYaw;                                       // 0x0140(0x0004) (CPF_Transient)
	int                                                DirectLookYaw;                                            // 0x0144(0x0004) (CPF_Transient)
	float                                              DirectLookInterpSpeed;                                    // 0x0148(0x0004) (CPF_Edit)
	float                                              WorstLocInterpSpeed;                                      // 0x014C(0x0004) (CPF_Edit)
	struct FVector                                     LastWorstLocationLocal;                                   // 0x0150(0x000C) (CPF_Transient)
	struct FVector                                     LastWorstLocation;                                        // 0x015C(0x000C) (CPF_Transient)
	struct FVector                                     LastPreModifierCameraLoc;                                 // 0x0168(0x000C) (CPF_Transient)
	struct FRotator                                    LastPreModifierCameraRot;                                 // 0x0174(0x000C) (CPF_Transient)
	TArray<struct FPenetrationAvoidanceFeeler>         PenetrationAvoidanceFeelers;                              // 0x0180(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	struct FVector                                     LastOffsetAdjustment;                                     // 0x018C(0x000C) (CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameThirdPersonCamera");
		return ptr;
	}


	void ResetInterpolation();
	void ModifyPostProcessSettings(struct FPostProcessSettings* PP);
	void OnBecomeActive(class UGameCameraBase* OldCamera);
	void ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator* out_ViewRotation, struct FRotator* out_DeltaRot);
	void UpdateCameraMode(class APawn* P);
	class UGameThirdPersonCameraMode* FindBestCameraMode(class APawn* P);
	void AdjustFocusPointInterpolation(const struct FRotator& Delta);
	struct FVector GetActualFocusLocation();
	void UpdateFocusPoint(class APawn* P);
	void ClearFocusPoint(bool bLeaveCameraRotation);
	class AActor* GetFocusActor();
	void SetFocusOnActor(class AActor* FocusActor, const struct FName& FocusBoneName, const struct FVector2D& InterpSpeedRange, const struct FVector2D& InFocusFOV, float CameraFOV, bool bAlwaysFocus, bool bAdjustCamera, bool bIgnoreTrace, float FocusPitchOffsetDeg);
	void SetFocusOnLoc(const struct FVector& FocusWorldLoc, const struct FVector2D& InterpSpeedRange, const struct FVector2D& InFocusFOV, float CameraFOV, bool bAlwaysFocus, bool bAdjustCamera, bool bIgnoreTrace, float FocusPitchOffsetDeg);
	void AdjustTurn(int AngleOffset);
	void EndTurn();
	void BeginTurn(int StartAngle, int EndAngle, float TimeSec, float DelaySec, bool bAlignTargetWhenFinished);
	void PlayerUpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget* OutVT);
	void UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget* OutVT);
	float GetDesiredFOV(class APawn* ViewedPawn);
	void Init();
	void Reset();
	class UGameThirdPersonCameraMode* CreateCameraMode(class UClass* ModeClass);
};


// Class GameFramework.GamePlayerCamera
// 0x0074 (0x0560 - 0x04EC)
class AGamePlayerCamera : public ACamera
{
public:
	class UGameCameraBase*                             ThirdPersonCam;                                           // 0x04EC(0x0004) (CPF_Edit, CPF_Transient, CPF_EditInline)
	class UClass*                                      ThirdPersonCameraClass;                                   // 0x04F0(0x0004) (CPF_Edit, CPF_Const)
	class UGameCameraBase*                             FixedCam;                                                 // 0x04F4(0x0004) (CPF_Edit, CPF_Transient, CPF_EditInline)
	class UClass*                                      FixedCameraClass;                                         // 0x04F8(0x0004) (CPF_Edit, CPF_Const)
	class UGameCameraBase*                             CurrentCamera;                                            // 0x04FC(0x0004) (CPF_Edit, CPF_Transient, CPF_EditInline)
	unsigned long                                      bUseForcedCamFOV : 1;                                     // 0x0500(0x0004) (CPF_Transient)
	unsigned long                                      bInterpolateCamChanges : 1;                               // 0x0500(0x0004) (CPF_Transient)
	unsigned long                                      bResetInterp : 1;                                         // 0x0500(0x0004) (CPF_Transient)
	float                                              ForcedCamFOV;                                             // 0x0504(0x0004) (CPF_Transient)
	class AActor*                                      LastViewTarget;                                           // 0x0508(0x0004) (CPF_Transient)
	float                                              SplitScreenShakeScale;                                    // 0x050C(0x0004) (CPF_Edit, CPF_Const)
	class AActor*                                      LastTargetBase;                                           // 0x0510(0x0004) (CPF_Transient)
	unsigned char                                      UnknownData00[0xC];                                       // 0x0514(0x000C) MISSED OFFSET
	struct FMatrix                                     LastTargetBaseTM;                                         // 0x0520(0x0040) (CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GamePlayerCamera");
		return ptr;
	}


	float AdjustFOVForViewport(float inHorizFOV, class APawn* CameraTargetPawn);
	void ProcessViewRotation(float DeltaTime, struct FRotator* out_ViewRotation, struct FRotator* out_DeltaRot);
	void ResetInterpolation();
	void SetColorScale(const struct FVector& NewColorScale);
	void DisplayDebug(class AHUD* HUD, float* out_YL, float* out_YPos);
	void UpdateCameraLensEffects(struct FTViewTarget* OutVT);
	void UpdateViewTarget(float DeltaTime, struct FTViewTarget* OutVT);
	bool ShouldConstrainAspectRatio();
	class UGameCameraBase* FindBestCameraType(class AActor* CameraTarget);
	void Reset();
	void PostBeginPlay();
	void CacheLastTargetBaseInfo(class AActor* TargetBase);
	class UGameCameraBase* CreateCamera(class UClass* CameraClass);
};


// Class GameFramework.GameThirdPersonCameraMode
// 0x01F1 (0x022D - 0x003C)
class UGameThirdPersonCameraMode : public UObject
{
public:
	class UGameThirdPersonCamera*                      ThirdPersonCam;                                           // 0x003C(0x0004) (CPF_Transient)
	float                                              FOVAngle;                                                 // 0x0040(0x0004) (CPF_Edit, CPF_Const, CPF_Config)
	float                                              BlendTime;                                                // 0x0044(0x0004) (CPF_Edit)
	unsigned long                                      bLockedToViewTarget : 1;                                  // 0x0048(0x0004) (CPF_Edit, CPF_Const)
	unsigned long                                      bDirectLook : 1;                                          // 0x0048(0x0004) (CPF_Edit, CPF_Const)
	unsigned long                                      bFollowTarget : 1;                                        // 0x0048(0x0004) (CPF_Edit, CPF_Const)
	unsigned long                                      bInterpLocation : 1;                                      // 0x0048(0x0004) (CPF_Edit)
	unsigned long                                      bUsePerAxisOriginLocInterp : 1;                           // 0x0048(0x0004) (CPF_Edit)
	unsigned long                                      bInterpRotation : 1;                                      // 0x0048(0x0004) (CPF_Edit)
	unsigned long                                      bRotInterpSpeedConstant : 1;                              // 0x0048(0x0004) (CPF_Edit)
	unsigned long                                      bDoPredictiveAvoidance : 1;                               // 0x0048(0x0004) (CPF_Edit, CPF_Const)
	unsigned long                                      bValidateWorstLoc : 1;                                    // 0x0048(0x0004) (CPF_Edit, CPF_Const)
	unsigned long                                      bSkipCameraCollision : 1;                                 // 0x0048(0x0004) (CPF_Edit)
	unsigned long                                      bSmoothViewOffsetPitchChanges : 1;                        // 0x0048(0x0004) (CPF_Edit, CPF_Const)
	unsigned long                                      bApplyDeltaViewOffset : 1;                                // 0x0048(0x0004) (CPF_Edit)
	unsigned long                                      bAdjustDOF : 1;                                           // 0x0048(0x0004) (CPF_Edit, CPF_Const)
	unsigned long                                      bDOFUpdated : 1;                                          // 0x0048(0x0004) (CPF_Transient)
	unsigned long                                      bNoFOVPostProcess : 1;                                    // 0x0048(0x0004)
	unsigned long                                      bInterpViewOffsetOnlyForCamTransition : 1;                // 0x0048(0x0004) (CPF_Edit)
	float                                              FollowingInterpSpeed_Pitch;                               // 0x004C(0x0004) (CPF_Edit, CPF_Const)
	float                                              FollowingInterpSpeed_Yaw;                                 // 0x0050(0x0004) (CPF_Edit, CPF_Const)
	float                                              FollowingInterpSpeed_Roll;                                // 0x0054(0x0004) (CPF_Edit, CPF_Const)
	float                                              FollowingCameraVelThreshold;                              // 0x0058(0x0004) (CPF_Edit, CPF_Const)
	float                                              OriginLocInterpSpeed;                                     // 0x005C(0x0004) (CPF_Edit)
	struct FVector                                     PerAxisOriginLocInterpSpeed;                              // 0x0060(0x000C) (CPF_Edit)
	float                                              OriginRotInterpSpeed;                                     // 0x006C(0x0004) (CPF_Edit)
	struct FVector                                     StrafeLeftAdjustment;                                     // 0x0070(0x000C) (CPF_Edit, CPF_Const)
	struct FVector                                     StrafeRightAdjustment;                                    // 0x007C(0x000C) (CPF_Edit, CPF_Const)
	float                                              StrafeOffsetScalingThreshold;                             // 0x0088(0x0004) (CPF_Edit, CPF_Const)
	float                                              StrafeOffsetInterpSpeedIn;                                // 0x008C(0x0004) (CPF_Edit, CPF_Const)
	float                                              StrafeOffsetInterpSpeedOut;                               // 0x0090(0x0004) (CPF_Edit, CPF_Const)
	struct FVector                                     LastStrafeOffset;                                         // 0x0094(0x000C) (CPF_Transient)
	struct FVector                                     RunFwdAdjustment;                                         // 0x00A0(0x000C) (CPF_Edit, CPF_Const)
	struct FVector                                     RunBackAdjustment;                                        // 0x00AC(0x000C) (CPF_Edit, CPF_Const)
	float                                              RunOffsetScalingThreshold;                                // 0x00B8(0x0004) (CPF_Edit, CPF_Const)
	float                                              RunOffsetInterpSpeedIn;                                   // 0x00BC(0x0004) (CPF_Edit, CPF_Const)
	float                                              RunOffsetInterpSpeedOut;                                  // 0x00C0(0x0004) (CPF_Edit, CPF_Const)
	struct FVector                                     LastRunOffset;                                            // 0x00C4(0x000C) (CPF_Transient)
	struct FVector                                     WorstLocOffset;                                           // 0x00D0(0x000C) (CPF_Edit)
	struct FVector                                     TargetRelativeCameraOriginOffset;                         // 0x00DC(0x000C) (CPF_Edit, CPF_Const)
	struct FViewOffsetData                             ViewOffset;                                               // 0x00E8(0x0024) (CPF_Edit, CPF_Const)
	struct FViewOffsetData                             ViewOffset_ViewportAdjustments[0x6];                      // 0x010C(0x0024) (CPF_Edit, CPF_Const)
	float                                              DOF_FalloffExponent;                                      // 0x01E4(0x0004) (CPF_Edit, CPF_Const)
	float                                              DOF_BlurKernelSize;                                       // 0x01E8(0x0004) (CPF_Edit, CPF_Const)
	float                                              DOF_FocusInnerRadius;                                     // 0x01EC(0x0004) (CPF_Edit, CPF_Const)
	float                                              DOF_MaxNearBlurAmount;                                    // 0x01F0(0x0004) (CPF_Edit, CPF_Const)
	float                                              DOF_MaxFarBlurAmount;                                     // 0x01F4(0x0004) (CPF_Edit, CPF_Const)
	float                                              LastDOFRadius;                                            // 0x01F8(0x0004) (CPF_Transient)
	float                                              LastDOFDistance;                                          // 0x01FC(0x0004) (CPF_Transient)
	float                                              DOFDistanceInterpSpeed;                                   // 0x0200(0x0004) (CPF_Edit, CPF_Const)
	struct FVector                                     DOFTraceExtent;                                           // 0x0204(0x000C) (CPF_Edit, CPF_Const)
	float                                              DOF_RadiusFalloff;                                        // 0x0210(0x0004) (CPF_Edit, CPF_Const)
	struct FVector2D                                   DOF_RadiusRange;                                          // 0x0214(0x0008) (CPF_Edit, CPF_Const)
	struct FVector2D                                   DOF_RadiusDistRange;                                      // 0x021C(0x0008) (CPF_Edit, CPF_Const)
	float                                              ViewOffsetInterp;                                         // 0x0224(0x0004)
	float                                              OffsetAdjustmentInterpSpeed;                              // 0x0228(0x0004) (CPF_Edit)
	TEnumAsByte<ECameraViewportTypes>                  CurrentViewportType;                                      // 0x022C(0x0001) (CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameThirdPersonCameraMode");
		return ptr;
	}


	void SetViewOffset(struct FViewOffsetData* NewViewOffset);
	void ModifyPostProcessSettings(struct FPostProcessSettings* PP);
	void UpdatePostProcess(float DeltaTime, struct FTViewTarget* VT);
	struct FVector DOFTrace(class AActor* TraceOwner, const struct FVector& StartTrace, const struct FVector& EndTrace);
	struct FVector GetDOFFocusLoc(class AActor* TraceOwner, const struct FVector& StartTrace, const struct FVector& EndTrace);
	void ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator* out_ViewRotation, struct FRotator* out_DeltaRot);
	bool SetFocusPoint(class APawn* ViewedPawn);
	struct FVector GetCameraWorstCaseLoc(class APawn* TargetPawn, const struct FTViewTarget& CurrentViewTarget);
	float GetDesiredFOV(class APawn* ViewedPawn);
	struct FVector AdjustViewOffset(class APawn* P, const struct FVector& Offset);
	void OnBecomeInActive(class APawn* TargetPawn, class UGameThirdPersonCameraMode* NewMode);
	void OnBecomeActive(class APawn* TargetPawn, class UGameThirdPersonCameraMode* PrevMode);
	void Init();
};


// Class GameFramework.GameThirdPersonCameraMode_Default
// 0x000F (0x023C - 0x022D)
class UGameThirdPersonCameraMode_Default : public UGameThirdPersonCameraMode
{
public:
	unsigned char                                      UnknownData00[0x3];                                       // 0x022D(0x0003) MISSED OFFSET
	float                                              WorstLocAimingZOffset;                                    // 0x0230(0x0004) (CPF_Edit, CPF_Const)
	unsigned long                                      bTemporaryOriginRotInterp : 1;                            // 0x0234(0x0004) (CPF_Transient)
	float                                              TemporaryOriginRotInterpSpeed;                            // 0x0238(0x0004) (CPF_Edit, CPF_Const)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameThirdPersonCameraMode_Default");
		return ptr;
	}

};


// Class GameFramework.GameSpecialMove
// 0x0040 (0x007C - 0x003C)
class UGameSpecialMove : public UObject
{
public:
	class AGamePawn*                                   PawnOwner;                                                // 0x003C(0x0004)
	struct FName                                       Handle;                                                   // 0x0040(0x0008)
	float                                              LastCanDoSpecialMoveTime;                                 // 0x0048(0x0004) (CPF_Transient)
	unsigned long                                      bLastCanDoSpecialMove : 1;                                // 0x004C(0x0004)
	unsigned long                                      bReachPreciseDestination : 1;                             // 0x004C(0x0004) (CPF_Const)
	unsigned long                                      bReachedPreciseDestination : 1;                           // 0x004C(0x0004) (CPF_Const)
	unsigned long                                      bReachPreciseRotation : 1;                                // 0x004C(0x0004) (CPF_Const)
	unsigned long                                      bReachedPreciseRotation : 1;                              // 0x004C(0x0004) (CPF_Const)
	unsigned long                                      bForcePrecisePosition : 1;                                // 0x004C(0x0004)
	struct FVector                                     PreciseDestination;                                       // 0x0050(0x000C) (CPF_Const)
	class AActor*                                      PreciseDestBase;                                          // 0x005C(0x0004) (CPF_Const)
	struct FVector                                     PreciseDestRelOffset;                                     // 0x0060(0x000C) (CPF_Const)
	float                                              PreciseRotationInterpolationTime;                         // 0x006C(0x0004) (CPF_Const)
	struct FRotator                                    PreciseRotation;                                          // 0x0070(0x000C) (CPF_Const)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameSpecialMove");
		return ptr;
	}


	struct FVector RelativeToWorldOffset(const struct FRotator& InRotation, const struct FVector& RelativeSpaceOffset);
	struct FVector WorldToRelativeOffset(const struct FRotator& InRotation, const struct FVector& WorldSpaceOffset);
	void ForcePawnRotation(class APawn* P, const struct FRotator& NewRotation);
	bool MessageEvent(const struct FName& EventName, class UObject* Sender);
	void ResetFacePreciseRotation();
	void ReachedPrecisePosition();
	void SetFacePreciseRotation(const struct FRotator& RotationToFace, float InterpolationTime);
	void SetReachPreciseDestination(const struct FVector& DestinationToReach, bool bCancel);
	bool ShouldReplicate();
	void SpecialMoveFlagsUpdated();
	void Tick(float DeltaTime);
	void SpecialMoveEnded(const struct FName& PrevMove, const struct FName& NextMove);
	void SpecialMoveStarted(bool bForced, const struct FName& PrevMove);
	bool InternalCanDoSpecialMove();
	bool CanDoSpecialMove(bool bForceCheck);
	bool CanOverrideSpecialMove(const struct FName& InMove);
	bool CanOverrideMoveWith(const struct FName& NewMove);
	bool CanChainMove(const struct FName& NextMove);
	void ExtractSpecialMoveFlags(int Flags);
	void InitSpecialMoveFlags(int* out_Flags);
	void InitSpecialMove(class AGamePawn* inPawn, const struct FName& InHandle);
};


// Class GameFramework.GameStateObject
// 0x0028 (0x0080 - 0x0058)
class UGameStateObject : public UGameplayEventsHandler
{
public:
	struct FArray_Mirror                               TeamStates;                                               // 0x0058(0x000C) (CPF_Const, CPF_Native)
	struct FArray_Mirror                               PlayerStates;                                             // 0x0064(0x000C) (CPF_Const, CPF_Native)
	TEnumAsByte<EGameSessionType>                      SessionType;                                              // 0x0070(0x0001)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0071(0x0003) MISSED OFFSET
	unsigned long                                      bIsMatchStarted : 1;                                      // 0x0074(0x0004)
	unsigned long                                      bIsRoundStarted : 1;                                      // 0x0074(0x0004)
	int                                                RoundNumber;                                              // 0x0078(0x0004)
	int                                                MaxRoundNumber;                                           // 0x007C(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameStateObject");
		return ptr;
	}


	void Reset();
	void PreProcessStream();
};


// Class GameFramework.GameStatsAggregator
// 0x01D8 (0x0230 - 0x0058)
class UGameStatsAggregator : public UGameplayEventsHandler
{
public:
	class UGameStateObject*                            GameState;                                                // 0x0058(0x0004)
	TArray<struct FAggregateEventMapping>              AggregatesList;                                           // 0x005C(0x000C) (CPF_NeedCtorLink)
	struct FMap_Mirror                                 AggregateEventsMapping;                                   // 0x0068(0x003C) (CPF_Const, CPF_Native, CPF_Transient)
	TArray<struct FGameplayEventMetaData>              AggregateEvents;                                          // 0x00A4(0x000C) (CPF_NeedCtorLink)
	TArray<int>                                        AggregatesFound;                                          // 0x00B0(0x000C) (CPF_Const, CPF_NeedCtorLink)
	struct FGameEvents                                 AllGameEvents;                                            // 0x00BC(0x003C)
	TArray<struct FTeamEvents>                         AllTeamEvents;                                            // 0x00F8(0x000C) (CPF_Const, CPF_NeedCtorLink)
	TArray<struct FPlayerEvents>                       AllPlayerEvents;                                          // 0x0104(0x000C) (CPF_Const, CPF_NeedCtorLink)
	struct FWeaponEvents                               AllWeaponEvents;                                          // 0x0110(0x0048) (CPF_Const, CPF_NeedCtorLink)
	struct FProjectileEvents                           AllProjectileEvents;                                      // 0x0158(0x0048) (CPF_Const, CPF_NeedCtorLink)
	struct FPawnEvents                                 AllPawnEvents;                                            // 0x01A0(0x0048) (CPF_Const, CPF_NeedCtorLink)
	struct FDamageEvents                               AllDamageEvents;                                          // 0x01E8(0x0048) (CPF_Const, CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameStatsAggregator");
		return ptr;
	}


	bool GetAggregateMappingIDs(int EventID, int* AggregateID, int* TargetAggregateID);
	void Reset();
	void PostProcessStream();
	void PreProcessStream();
};


// Class GameFramework.SeqAct_ToggleMouseCursor
// 0x0000 (0x00FC - 0x00FC)
class USeqAct_ToggleMouseCursor : public USequenceAction
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqAct_ToggleMouseCursor");
		return ptr;
	}

};


// Class GameFramework.GameWaveForms
// 0x0010 (0x004C - 0x003C)
class UGameWaveForms : public UObject
{
public:
	class UForceFeedbackWaveform*                      CameraShakeMediumShort;                                   // 0x003C(0x0004)
	class UForceFeedbackWaveform*                      CameraShakeMediumLong;                                    // 0x0040(0x0004)
	class UForceFeedbackWaveform*                      CameraShakeBigShort;                                      // 0x0044(0x0004)
	class UForceFeedbackWaveform*                      CameraShakeBigLong;                                       // 0x0048(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameWaveForms");
		return ptr;
	}

};


// Class GameFramework.DebugCameraHUD
// 0x0004 (0x049C - 0x0498)
class ADebugCameraHUD : public AHUD
{
public:
	unsigned long                                      bDrawDebugText : 1;                                       // 0x0498(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.DebugCameraHUD");
		return ptr;
	}


	void PostRender();
	bool DisplayMaterials(float X, float DY, class UMeshComponent* MeshComp, float* Y);
	void PostBeginPlay();
};


// Class GameFramework.DebugCameraInput
// 0x0000 (0x0270 - 0x0270)
class UDebugCameraInput : public UPlayerInput
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.DebugCameraInput");
		return ptr;
	}


	bool InputKey(int ControllerId, const struct FName& Key, TEnumAsByte<EInputEvent> Event, float AmountDepressed, bool bGamepad);
};


// Class GameFramework.GameCrowdSpawnerInterface
// 0x0000 (0x003C - 0x003C)
class UGameCrowdSpawnerInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdSpawnerInterface");
		return ptr;
	}


	float GetMaxSpawnDist();
	void AgentDestroyed(class AGameCrowdAgent* Agent);
};


// Class GameFramework.GameCrowdSpawnInterface
// 0x0000 (0x003C - 0x003C)
class UGameCrowdSpawnInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdSpawnInterface");
		return ptr;
	}


	void GetSpawnPosition(class USeqAct_GameCrowdSpawner* Spawner, struct FVector* SpawnPos, struct FRotator* SpawnRot);
};


// Class GameFramework.DynamicGameCrowdDestination
// 0x0000 (0x0298 - 0x0298)
class ADynamicGameCrowdDestination : public AGameCrowdDestination
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.DynamicGameCrowdDestination");
		return ptr;
	}

};


// Class GameFramework.GameAICmd_Hover_MoveToGoal
// 0x0034 (0x008C - 0x0058)
class UGameAICmd_Hover_MoveToGoal : public UGameAICommand
{
public:
	class AActor*                                      Path;                                                     // 0x0058(0x0004) (CPF_Transient)
	class AActor*                                      Find;                                                     // 0x005C(0x0004) (CPF_Transient)
	class AActor*                                      Goal;                                                     // 0x0060(0x0004) (CPF_Transient)
	float                                              Radius;                                                   // 0x0064(0x0004)
	unsigned long                                      bWasFiring : 1;                                           // 0x0068(0x0004) (CPF_Transient)
	float                                              DesiredHoverHeight;                                       // 0x006C(0x0004)
	float                                              CurrentHoverHeight;                                       // 0x0070(0x0004) (CPF_Transient)
	float                                              SubGoalReachDist;                                         // 0x0074(0x0004)
	float                                              GoalDistance;                                             // 0x0078(0x0004)
	struct FVector                                     MoveVectDest;                                             // 0x007C(0x000C) (CPF_Transient)
	class UReachSpec*                                  CurrentSpec;                                              // 0x0088(0x0004) (CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameAICmd_Hover_MoveToGoal");
		return ptr;
	}


	bool IsEnemyBasedOnInterpActor(class APawn* InEnemy);
	bool HandlePathObstruction(class AActor* BlockedBy);
	void Pushed();
	bool STATIC_MoveToGoal(class AGameAIController* AI, class AActor* InGoal, float InGoalDistance, float InHoverHeight);
};


// Class GameFramework.GameAICmd_Hover_MoveToGoal_Mesh
// 0x008C (0x00E4 - 0x0058)
class UGameAICmd_Hover_MoveToGoal_Mesh : public UGameAICommand
{
public:
	class AActor*                                      Find;                                                     // 0x0058(0x0004) (CPF_Transient)
	float                                              Radius;                                                   // 0x005C(0x0004)
	unsigned long                                      bWasFiring : 1;                                           // 0x0060(0x0004) (CPF_Transient)
	unsigned long                                      bFinalApproach : 1;                                       // 0x0060(0x0004)
	unsigned long                                      bFallbackMoveToMesh : 1;                                  // 0x0060(0x0004)
	float                                              DesiredHoverHeight;                                       // 0x0064(0x0004)
	float                                              CurrentHoverHeight;                                       // 0x0068(0x0004) (CPF_Transient)
	float                                              SubGoalReachDist;                                         // 0x006C(0x0004)
	float                                              GoalDistance;                                             // 0x0070(0x0004) (CPF_Transient)
	struct FVector                                     IntermediatePoint;                                        // 0x0074(0x000C) (CPF_Transient)
	struct FVector                                     LastMovePoint;                                            // 0x0080(0x000C) (CPF_Transient)
	int                                                NumMovePointFails;                                        // 0x008C(0x0004) (CPF_Transient)
	int                                                MaxMovePointFails;                                        // 0x0090(0x0004)
	struct FVector                                     FallbackDest;                                             // 0x0094(0x000C) (CPF_Transient)
	class AActor*                                      MoveToActor;                                              // 0x00A0(0x0004) (CPF_Transient)
	struct FBasedPosition                              LastMoveTargetPathLocation;                               // 0x00A4(0x0034)
	struct FVector                                     InitialFinalDestination;                                  // 0x00D8(0x000C) (CPF_Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameAICmd_Hover_MoveToGoal_Mesh");
		return ptr;
	}


	void DrawDebug(class AHUD* H, const struct FName& Category);
	bool IsEnemyBasedOnInterpActor(class APawn* InEnemy);
	bool ShouldUpdateBreadCrumbs();
	bool HasReachedGoal();
	void ReEvaluatePath();
	bool HandlePathObstruction(class AActor* BlockedBy);
	void Tick(float DeltaTime);
	void Popped();
	void Pushed();
	bool STATIC_HoverBackToMesh(class AGameAIController* AI);
	bool STATIC_HoverToPoint(class AGameAIController* AI, const struct FVector& InPoint, float InGoalDistance, float InHoverHeight);
	bool STATIC_HoverToGoal(class AGameAIController* AI, class AActor* InGoal, float InGoalDistance, float InHoverHeight);
};


// Class GameFramework.GameCrowd_ListOfAgents
// 0x000C (0x0048 - 0x003C)
class UGameCrowd_ListOfAgents : public UObject
{
public:
	TArray<struct FAgentArchetypeInfo>                 ListOfAgents;                                             // 0x003C(0x000C) (CPF_Edit, CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowd_ListOfAgents");
		return ptr;
	}

};


// Class GameFramework.GameCrowdInteractionDestination
// 0x0000 (0x0298 - 0x0298)
class AGameCrowdInteractionDestination : public AGameCrowdDestination
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameCrowdInteractionDestination");
		return ptr;
	}

};


// Class GameFramework.GameExplosionContent
// 0x0048 (0x0084 - 0x003C)
class UGameExplosionContent : public UObject
{
public:
	unsigned long                                      bAutoControllerVibration : 1;                             // 0x003C(0x0004) (CPF_Edit, CPF_Const)
	unsigned long                                      bOrientCameraShakeTowardsEpicenter : 1;                   // 0x003C(0x0004) (CPF_Edit, CPF_Const)
	class USoundCue*                                   ExplosionSound;                                           // 0x0040(0x0004) (CPF_Edit, CPF_Const)
	class UCameraShake*                                CamShake;                                                 // 0x0044(0x0004) (CPF_Edit, CPF_Const)
	class UCameraShake*                                CamShake_Left;                                            // 0x0048(0x0004) (CPF_Edit, CPF_Const)
	class UCameraShake*                                CamShake_Right;                                           // 0x004C(0x0004) (CPF_Edit, CPF_Const)
	class UCameraShake*                                CamShake_Rear;                                            // 0x0050(0x0004) (CPF_Edit, CPF_Const)
	float                                              CamShakeInnerRadius;                                      // 0x0054(0x0004) (CPF_Edit, CPF_Const)
	float                                              CamShakeOuterRadius;                                      // 0x0058(0x0004) (CPF_Edit, CPF_Const)
	float                                              CamShakeFalloff;                                          // 0x005C(0x0004) (CPF_Edit, CPF_Const)
	class UClass*                                      CameraLensEffect;                                         // 0x0060(0x0004) (CPF_Edit, CPF_Const)
	float                                              CameraLensEffectRadius;                                   // 0x0064(0x0004) (CPF_Edit, CPF_Const)
	class UPointLightComponent*                        ExploLight;                                               // 0x0068(0x0004) (CPF_Edit, CPF_Const, CPF_ExportObject, CPF_Component, CPF_EditInline)
	float                                              ExploLightFadeOutTime;                                    // 0x006C(0x0004) (CPF_Edit, CPF_Const)
	class URadialBlurComponent*                        ExploRadialBlur;                                          // 0x0070(0x0004) (CPF_Edit, CPF_Const, CPF_ExportObject, CPF_Component, CPF_EditInline)
	float                                              ExploRadialBlurFadeOutTime;                               // 0x0074(0x0004) (CPF_Edit, CPF_Const)
	float                                              ExploRadialBlurMaxBlur;                                   // 0x0078(0x0004) (CPF_Edit, CPF_Const)
	class UParticleSystem*                             ParticleEmitterTemplate;                                  // 0x007C(0x0004) (CPF_Edit, CPF_Const)
	class AFogVolumeSphericalDensityInfo*              FogVolumeArchetype;                                       // 0x0080(0x0004) (CPF_Edit, CPF_Const)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameExplosionContent");
		return ptr;
	}

};


// Class GameFramework.GameFixedCamera
// 0x0004 (0x0048 - 0x0044)
class UGameFixedCamera : public UGameCameraBase
{
public:
	float                                              DefaultFOV;                                               // 0x0044(0x0004) (CPF_Edit, CPF_Const)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameFixedCamera");
		return ptr;
	}


	void OnBecomeActive(class UGameCameraBase* OldCamera);
	void UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget* OutVT);
};


// Class GameFramework.GameKActorSpawnableEffect
// 0x0000 (0x0308 - 0x0308)
class AGameKActorSpawnableEffect : public AKActor
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.GameKActorSpawnableEffect");
		return ptr;
	}


	void StartScalingDown();
	void FellOutOfWorld(class UClass* dmgType);
	void PostBeginPlay();
};


// Class GameFramework.MobileDebugCameraController
// 0x0008 (0x061C - 0x0614)
class AMobileDebugCameraController : public ADebugCameraController
{
public:
	int                                                OldMobileGroup;                                           // 0x0614(0x0004)
	class UMobilePlayerInput*                          MPI;                                                      // 0x0618(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileDebugCameraController");
		return ptr;
	}


	void SetupDebugZones();
	void InitInputSystem();
	void OnDeactivate(class APlayerController* PC);
	void InitDebugInputSystem();
	void OnActivate(class APlayerController* PC);
};


// Class GameFramework.MobileDebugCameraInput
// 0x0000 (0x04B4 - 0x04B4)
class UMobileDebugCameraInput : public UMobilePlayerInput
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileDebugCameraInput");
		return ptr;
	}


	bool InputKey(int ControllerId, const struct FName& Key, TEnumAsByte<EInputEvent> Event, float AmountDepressed, bool bGamepad);
};


// Class GameFramework.MobileDebugCameraHUD
// 0x0004 (0x0588 - 0x0584)
class AMobileDebugCameraHUD : public AMobileHUD
{
public:
	unsigned long                                      bDrawDebugText : 1;                                       // 0x0584(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileDebugCameraHUD");
		return ptr;
	}


	void PostRender();
	bool DisplayMaterials(float X, float DY, class UMeshComponent* MeshComp, float* Y);
	void PostBeginPlay();
};


// Class GameFramework.MobileMenuBar
// 0x0018 (0x00BC - 0x00A4)
class UMobileMenuBar : public UMobileMenuObject
{
public:
	unsigned long                                      bIsVertical : 1;                                          // 0x00A4(0x0004) (CPF_Edit)
	unsigned long                                      bDirty : 1;                                               // 0x00A4(0x0004)
	int                                                SelectedIndex;                                            // 0x00A8(0x0004) (CPF_Edit)
	int                                                FirstItem;                                                // 0x00AC(0x0004)
	TArray<class UMobileMenuBarItem*>                  Items;                                                    // 0x00B0(0x000C) (CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuBar");
		return ptr;
	}


	void UpdateItemViewports();
	void SetFirstItem(int First);
	void RenderItem(class UCanvas* Canvas, float DeltaTime, int ItemIndex);
	void RenderObject(class UCanvas* Canvas, float DeltaTime);
	bool OnTouch(TEnumAsByte<ETouchType> EventType, float TouchX, float TouchY, class UMobileMenuObject* ObjectOver, float DeltaTime);
	class UMobileMenuBarItem* GetSelected();
	int Num();
	void AddItem(class UMobileMenuBarItem* Item, int Index);
	void InitMenuObject(class UMobilePlayerInput* PlayerInput, class UMobileMenuScene* Scene, int ScreenWidth, int ScreenHeight, bool bIsFirstInitialization);
};


// Class GameFramework.MobileMenuBarItem
// 0x0010 (0x004C - 0x003C)
class UMobileMenuBarItem : public UObject
{
public:
	int                                                Width;                                                    // 0x003C(0x0004)
	int                                                Height;                                                   // 0x0040(0x0004)
	struct FVector2D                                   VpPos;                                                    // 0x0044(0x0008)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuBarItem");
		return ptr;
	}


	void RenderItem(class UMobileMenuBar* Bar, class UCanvas* Canvas, float DeltaTime);
};


// Class GameFramework.MobileMenuButton
// 0x005C (0x0100 - 0x00A4)
class UMobileMenuButton : public UMobileMenuObject
{
public:
	class UTexture2D*                                  Images[0x2];                                              // 0x00A4(0x0004)
	struct FUVCoords                                   ImagesUVs[0x2];                                           // 0x00AC(0x0014)
	struct FLinearColor                                ImageColor;                                               // 0x00D4(0x0010)
	struct FString                                     Caption;                                                  // 0x00E4(0x000C) (CPF_NeedCtorLink)
	struct FLinearColor                                CaptionColor;                                             // 0x00F0(0x0010)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuButton");
		return ptr;
	}


	void RenderCaption(class UCanvas* Canvas);
	void RenderObject(class UCanvas* Canvas, float DeltaTime);
	void InitMenuObject(class UMobilePlayerInput* PlayerInput, class UMobileMenuScene* Scene, int ScreenWidth, int ScreenHeight, bool bIsFirstInitialization);
};


// Class GameFramework.MobileMenuElement
// 0x0014 (0x0050 - 0x003C)
class UMobileMenuElement : public UObject
{
public:
	struct FVector2D                                   VpPos;                                                    // 0x003C(0x0008)
	struct FVector2D                                   VpSize;                                                   // 0x0044(0x0008)
	unsigned long                                      bIsVisible : 1;                                           // 0x004C(0x0004)
	unsigned long                                      bIsActive : 1;                                            // 0x004C(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuElement");
		return ptr;
	}


	void RenderElement(class UMobileMenuObject* Owner, class UCanvas* Canvas, float DeltaTime, float Opacity);
	bool OnTouch(TEnumAsByte<ETouchType> EventType, float TouchX, float TouchY, float DeltaTime);
};


// Class GameFramework.MobileMenuGame
// 0x0004 (0x03E4 - 0x03E0)
class AMobileMenuGame : public AGameInfo
{
public:
	class UClass*                                      InitialSceneToDisplayClass;                               // 0x03E0(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuGame");
		return ptr;
	}


	void RestartPlayer(class AController* NewPlayer);
	void StartMatch();
	void PostLogin(class APlayerController* NewPlayer);
};


// Class GameFramework.MobileMenuPlayerController
// 0x0000 (0x05E0 - 0x05E0)
class AMobileMenuPlayerController : public AGamePlayerController
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuPlayerController");
		return ptr;
	}

};


// Class GameFramework.MobileMenuInventory
// 0x0088 (0x012C - 0x00A4)
class UMobileMenuInventory : public UMobileMenuObject
{
public:
	TArray<class UMobileMenuElement*>                  Slots;                                                    // 0x00A4(0x000C) (CPF_NeedCtorLink)
	TArray<class UMobileMenuElement*>                  Items;                                                    // 0x00B0(0x000C) (CPF_NeedCtorLink)
	float                                              SideLeewayPercent;                                        // 0x00BC(0x0004)
	struct FRenderElementInfo                          CurrentElement;                                           // 0x00C0(0x0008)
	struct FDragElementInfo                            Drag;                                                     // 0x00C8(0x0028)
	struct FVector2D                                   ScaleSize;                                                // 0x00F0(0x0008)
	unsigned long                                      bRenderDragItem : 1;                                      // 0x00F8(0x0004)
	struct FScriptDelegate                             __OnUpdateItemInSlot__Delegate;                           // 0x00FC(0x0010) (CPF_NeedCtorLink)
	struct FScriptDelegate                             __DoCanPutItemInSlot__Delegate;                           // 0x010C(0x0010) (CPF_NeedCtorLink)
	struct FScriptDelegate                             __OnUpdateDrag__Delegate;                                 // 0x011C(0x0010) (CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuInventory");
		return ptr;
	}


	void RenderDragItem(class UCanvas* Canvas, float DeltaTime);
	void RenderObject(class UCanvas* Canvas, float DeltaTime);
	int GetIndexOfItem(class UMobileMenuElement* Item);
	int FindSlotIndexAt(float X, float Y);
	void InitDragAt(int TouchX, int TouchY);
	void UpdateItemInSlot(int InSlot);
	class UMobileMenuElement* AddItemToSlot(class UMobileMenuElement* Element, int ToSlot);
	bool SwapItemsInSlots(int Slot0, int Slot1);
	bool OnTouch(TEnumAsByte<ETouchType> EventType, float TouchX, float TouchY, class UMobileMenuObject* ObjectOver, float DeltaTime);
	bool CanPutItemInSlot(class UMobileMenuElement* Item, class UMobileMenuElement* ToSlot, int ToIdx, int FromIdx);
	void ScaleSlot(class UMobileMenuElement* Slot);
	int AddSlot(class UMobileMenuElement* Slot);
	void InitMenuObject(class UMobilePlayerInput* PlayerInput, class UMobileMenuScene* Scene, int ScreenWidth, int ScreenHeight, bool bIsFirstInitialization);
	void OnUpdateDrag(struct FDragElementInfo* Before, struct FDragElementInfo* After);
	bool DoCanPutItemInSlot(class UMobileMenuInventory* FromInv, class UMobileMenuElement* Item, class UMobileMenuElement* ToSlot, int ToIdx, int FromIdx);
	void OnUpdateItemInSlot(class UMobileMenuInventory* FromInv, int SlotIndex);
};


// Class GameFramework.MobileMenuLabel
// 0x0024 (0x00C8 - 0x00A4)
class UMobileMenuLabel : public UMobileMenuObject
{
public:
	struct FString                                     Caption;                                                  // 0x00A4(0x000C) (CPF_NeedCtorLink)
	class UFont*                                       TextFont;                                                 // 0x00B0(0x0004)
	struct FColor                                      TextColor;                                                // 0x00B4(0x0004)
	struct FColor                                      TouchedColor;                                             // 0x00B8(0x0004)
	float                                              TextXScale;                                               // 0x00BC(0x0004)
	float                                              TextYScale;                                               // 0x00C0(0x0004)
	unsigned long                                      bAutoSize : 1;                                            // 0x00C4(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuLabel");
		return ptr;
	}


	void RenderObject(class UCanvas* Canvas, float DeltaTime);
};


// Class GameFramework.MobileMenuList
// 0x00AC (0x0150 - 0x00A4)
class UMobileMenuList : public UMobileMenuObject
{
public:
	unsigned long                                      bIsVerticalList : 1;                                      // 0x00A4(0x0004) (CPF_Edit)
	unsigned long                                      bDisableScrolling : 1;                                    // 0x00A4(0x0004) (CPF_Edit)
	unsigned long                                      bForceSelectedToLineup : 1;                               // 0x00A4(0x0004) (CPF_Edit)
	unsigned long                                      bTapToScrollToItem : 1;                                   // 0x00A4(0x0004)
	unsigned long                                      bLoops : 1;                                               // 0x00A4(0x0004)
	float                                              SelectedOffset;                                           // 0x00A8(0x0004) (CPF_Edit)
	TArray<class UMobileMenuListItem*>                 Items;                                                    // 0x00AC(0x000C) (CPF_NeedCtorLink)
	struct FSelectedMenuItem                           SelectedItem;                                             // 0x00B8(0x000C)
	struct FMenuListDragInfo                           Drag;                                                     // 0x00C4(0x0050)
	struct FMenuListMovementInfo                       Movement;                                                 // 0x0114(0x001C)
	float                                              Deacceleration;                                           // 0x0130(0x0004)
	float                                              EaseOutExp;                                               // 0x0134(0x0004)
	struct FIntPoint                                   ScreenSize;                                               // 0x0138(0x0008)
	int                                                FirstVisible;                                             // 0x0140(0x0004)
	int                                                LastVisible;                                              // 0x0144(0x0004)
	int                                                NumShowEndOfList;                                         // 0x0148(0x0004)
	float                                              EndOfListSupression;                                      // 0x014C(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuList");
		return ptr;
	}


	int ItemScrollSize(class UMobileMenuListItem* Item);
	void RenderObject(class UCanvas* Canvas, float DeltaTime);
	void UpdateScroll(float DeltaTime);
	float CalculateSelectedItem(float ScrollAmount, bool bForceZeroAdjustment, struct FSelectedMenuItem* Selected);
	class UMobileMenuListItem* GetItemClickPosition(float* MouseX, float* MouseY);
	bool OnTouch(TEnumAsByte<ETouchType> EventType, float TouchX, float TouchY, class UMobileMenuObject* ObjectOver, float DeltaTime);
	bool SetSelectedItem(int ItemIndex, bool bForceAll);
	int GetNumVisible();
	int SetSelectedToVisibleIndex(int VisibleIndex);
	int GetVisibleIndexOfSelected();
	float GetAmountSelected(class UMobileMenuListItem* Item);
	class UMobileMenuListItem* GetSelected();
	int Num();
	void AddItem(class UMobileMenuListItem* Item, int Index);
	void InitMenuObject(class UMobilePlayerInput* PlayerInput, class UMobileMenuScene* Scene, int ScreenWidth, int ScreenHeight, bool bIsFirstInitialization);
};


// Class GameFramework.MobileMenuListItem
// 0x0008 (0x0058 - 0x0050)
class UMobileMenuListItem : public UMobileMenuElement
{
public:
	float                                              Width;                                                    // 0x0050(0x0004)
	float                                              Height;                                                   // 0x0054(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuListItem");
		return ptr;
	}


	void RenderItem(class UMobileMenuList* List, class UCanvas* Canvas, float DeltaTime);
};


// Class GameFramework.MobileMenuObjectProxy
// 0x0020 (0x00C4 - 0x00A4)
class UMobileMenuObjectProxy : public UMobileMenuObject
{
public:
	struct FScriptDelegate                             __OnTouchEvent__Delegate;                                 // 0x00A4(0x0010) (CPF_NeedCtorLink)
	struct FScriptDelegate                             __OnRenderObject__Delegate;                               // 0x00B4(0x0010) (CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileMenuObjectProxy");
		return ptr;
	}


	void RenderObject(class UCanvas* Canvas, float DeltaTime);
	bool OnTouch(TEnumAsByte<ETouchType> EventType, float TouchX, float TouchY, class UMobileMenuObject* ObjectOver, float DeltaTime);
	void OnRenderObject(class UMobileMenuObjectProxy* Proxy, class UCanvas* Canvas, float DeltaTime);
	bool OnTouchEvent(class UMobileMenuObjectProxy* Proxy, TEnumAsByte<ETouchType> EventType, float TouchX, float TouchY, class UMobileMenuObject* ObjectOver, float DeltaTime);
};


// Class GameFramework.MobileTouchInputVolume
// 0x0004 (0x0240 - 0x023C)
class AMobileTouchInputVolume : public AVolume
{
public:
	unsigned long                                      bEnabled : 1;                                             // 0x023C(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.MobileTouchInputVolume");
		return ptr;
	}


	void HandleDragOver();
	void HandleDoubleClick();
	void HandleClick();
	void OnToggle(class USeqAct_Toggle* inAction);
};


// Class GameFramework.SeqEvent_MobileTouchInputVolume
// 0x0000 (0x0114 - 0x0114)
class USeqEvent_MobileTouchInputVolume : public USequenceEvent
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_MobileTouchInputVolume");
		return ptr;
	}

};


// Class GameFramework.TouchableElement3D
// 0x0000 (0x003C - 0x003C)
class UTouchableElement3D : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.TouchableElement3D");
		return ptr;
	}


	void HandleDragOver();
	void HandleDoubleClick();
	void HandleClick();
};


// Class GameFramework.PlayerCollectorGame
// 0x0010 (0x03F0 - 0x03E0)
class APlayerCollectorGame : public AGameInfo
{
public:
	int                                                NumberOfClientsToWaitFor;                                 // 0x03E0(0x0004)
	struct FString                                     URLToLoad;                                                // 0x03E4(0x000C) (CPF_NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.PlayerCollectorGame");
		return ptr;
	}


	void GetSeamlessTravelActorList(bool bToEntry, TArray<class AActor*>* ActorList);
	class APlayerController* Login(const struct FString& Portal, const struct FString& Options, const struct FUniqueNetId& UniqueId, struct FString* ErrorMessage);
};


// Class GameFramework.PMESTG_LeaveADecalBase
// 0x0004 (0x0040 - 0x003C)
class UPMESTG_LeaveADecalBase : public UParticleModuleEventSendToGame
{
public:
	class UClass*                                      PhysicalMaterialPropertyClass;                            // 0x003C(0x0004)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.PMESTG_LeaveADecalBase");
		return ptr;
	}

};


// Class GameFramework.SeqEvent_HudRenderImage
// 0x0038 (0x0160 - 0x0128)
class USeqEvent_HudRenderImage : public USeqEvent_HudRender
{
public:
	struct FLinearColor                                DisplayColor;                                             // 0x0128(0x0010) (CPF_Edit)
	struct FVector                                     DisplayLocation;                                          // 0x0138(0x000C) (CPF_Edit)
	class UTexture2D*                                  DisplayTexture;                                           // 0x0144(0x0004) (CPF_Edit)
	float                                              XL;                                                       // 0x0148(0x0004) (CPF_Edit)
	float                                              YL;                                                       // 0x014C(0x0004) (CPF_Edit)
	float                                              U;                                                        // 0x0150(0x0004) (CPF_Edit)
	float                                              V;                                                        // 0x0154(0x0004) (CPF_Edit)
	float                                              UL;                                                       // 0x0158(0x0004) (CPF_Edit)
	float                                              VL;                                                       // 0x015C(0x0004) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_HudRenderImage");
		return ptr;
	}


	void Render(class UCanvas* TargetCanvas, class AHUD* TargetHud);
};


// Class GameFramework.SeqEvent_HudRenderText
// 0x0021 (0x0149 - 0x0128)
class USeqEvent_HudRenderText : public USeqEvent_HudRender
{
public:
	class UFont*                                       DisplayFont;                                              // 0x0128(0x0004) (CPF_Edit)
	struct FColor                                      DisplayColor;                                             // 0x012C(0x0004) (CPF_Edit)
	struct FVector                                     DisplayLocation;                                          // 0x0130(0x000C) (CPF_Edit)
	struct FString                                     DisplayText;                                              // 0x013C(0x000C) (CPF_Edit, CPF_NeedCtorLink)
	TEnumAsByte<ETextDrawMethod>                       TextDrawMethod;                                           // 0x0148(0x0001) (CPF_Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class GameFramework.SeqEvent_HudRenderText");
		return ptr;
	}


	int STATIC_GetObjClassVersion();
	void Render(class UCanvas* TargetCanvas, class AHUD* TargetHud);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif