#pragma once

struct FWeakObjectPtr
{
	int ObjectIndex;
	int ObjectSerialNumber;

	void operator=(UObject const* __that) { return NativeCall<void, UObject const*>(this, "FWeakObjectPtr.operator=(UObject*)", __that); }
	UObject* Get(bool bEvenIfPendingKill = false) { return NativeCall<UObject*, bool>(this, "FWeakObjectPtr.Get(bool)", bEvenIfPendingKill); }
	bool IsValid() { return NativeCall<bool>(this, "FWeakObjectPtr.IsValid()"); }
};

template <typename T>
struct TWeakObjectPtr
{
	int ObjectIndex;
	int ObjectSerialNumber;

	FORCEINLINE T& operator*()
	{
		return *Get();
	}

	FORCEINLINE T* operator->()
	{
		return Get();
	}

	T* Get(bool bEvenIfPendingKill = false)
	{
		return NativeCall<T*, bool>(this, "FWeakObjectPtr.Get()", bEvenIfPendingKill);
	}

	FORCEINLINE operator bool()
	{
		return Get() != nullptr;
	}

	FORCEINLINE operator T* ()
	{
		return Get();
	}

	FORCEINLINE bool operator==(const TWeakObjectPtr<T>& __that) const
	{
		return this->ObjectIndex == __that.ObjectIndex
			&& this->ObjectSerialNumber == __that.ObjectSerialNumber;
	}

	TWeakObjectPtr()
	{}

	TWeakObjectPtr(int index, int serialnumber)
		:ObjectIndex(index),
		ObjectSerialNumber(serialnumber)
	{}
};

struct FObjectHandlePrivate
{
	//Stores either FPackedObjectRef or a UObject*
	UPTRINT PointerOrRef;

	explicit inline operator bool() const
	{
		return PointerOrRef != 0;
	}

};

template <typename T>
struct TObjectPtr
{
private:
	FObjectHandlePrivate Handle;
	FORCEINLINE UObject* RealGet() const { return reinterpret_cast<UObject*>(Handle.PointerOrRef); }	
public:

	FORCEINLINE T* Get() const { return (T*)(RealGet()); }
	FORCEINLINE T* operator->() const { return Get(); }
	FORCEINLINE T& operator*() const { return *Get(); }
};

struct UObjectBase
{
	// Fields

	UObjectBase_vtbl*& __vftableField() { return *GetNativePointerField<UObjectBase_vtbl**>(this, "UObjectBase.__vftable"); }
	EObjectFlags& ObjectFlagsField() { return *GetNativePointerField<EObjectFlags*>(this, "UObjectBase.ObjectFlags"); }
	int& InternalIndexField() { return *GetNativePointerField<int*>(this, "UObjectBase.InternalIndex"); }
	UClass*& ClassPrivateField() { return *GetNativePointerField<UClass**>(this, "UObjectBase.ClassPrivate"); }
	FName& NamePrivateField() { return *GetNativePointerField<FName*>(this, "UObjectBase.NamePrivate"); }
	UObject*& OuterPrivateField() { return *GetNativePointerField<UObject**>(this, "UObjectBase.OuterPrivate"); }

	// Bitfields


	// Functions

	//void AtomicallyClearFlags(EObjectFlags FlagsToClear) { NativeCall<void, EObjectFlags>(this, "UObjectBase.AtomicallyClearFlags(EObjectFlags)", FlagsToClear); }
	//void ~UObjectBase() { NativeCall<void>(this, "UObjectBase.~UObjectBase()"); }
	void DeferredRegister(UClass* UClassStaticClass, const wchar_t* PackageName, const wchar_t* InName) { NativeCall<void, UClass*, const wchar_t*, const wchar_t*>(this, "UObjectBase.DeferredRegister(UClass*,wchar_t*,wchar_t*)", UClassStaticClass, PackageName, InName); }
	//void AddObject(FName InName, EInternalObjectFlags InSetInternalFlags, int InInternalIndex, int InSerialNumber) { NativeCall<void, FName, EInternalObjectFlags, int, int>(this, "UObjectBase.AddObject(FName,EInternalObjectFlags,int,int)", InName, InSetInternalFlags, InInternalIndex, InSerialNumber); }
	UPackage* GetExternalPackageInternal() { return NativeCall<UPackage*>(this, "UObjectBase.GetExternalPackageInternal()"); }
	void SetExternalPackage(UPackage* InPackage) { NativeCall<void, UPackage*>(this, "UObjectBase.SetExternalPackage(UPackage*)", InPackage); }
	bool IsValidLowLevel() { return NativeCall<bool>(this, "UObjectBase.IsValidLowLevel()"); }
	bool IsValidLowLevelFast(bool bRecursive) { return NativeCall<bool, bool>(this, "UObjectBase.IsValidLowLevelFast(bool)", bRecursive); }
};

struct UObjectBaseUtility : UObjectBase
{
	// Fields


	  // Bitfields


	  // Functions

	//bool IsA<class UGameEngine>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UGameEngine>()"); }
	//bool IsA<class UClass>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UClass>()"); }
	//bool IsA<class AActor>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AActor>()"); }
	//bool IsA<class ACharacter>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ACharacter>()"); }
	//bool IsA<class ULevel>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ULevel>()"); }
	//bool IsA<class UCapsuleComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UCapsuleComponent>()"); }
	//UNiagaraSystem* GetTypedOuter<class UNiagaraSystem>() { return NativeCall<UNiagaraSystem*>(this, "UObjectBaseUtility.GetTypedOuter<class UNiagaraSystem>()"); }
	//bool IsA<class UActorComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UActorComponent>()"); }
	//bool IsA<class USceneComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class USceneComponent>()"); }
	//bool IsA<class UPrimitiveComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimitiveComponent>()"); }
	//USkeletalMeshComponent* GetTypedOuter<class USkeletalMeshComponent>() { return NativeCall<USkeletalMeshComponent*>(this, "UObjectBaseUtility.GetTypedOuter<class USkeletalMeshComponent>()"); }
	//bool IsA<class USkeletalMeshComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class USkeletalMeshComponent>()"); }
	//bool IsA<class UStaticMeshComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UStaticMeshComponent>()"); }
	//bool IsA<class UMaterialInterface>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMaterialInterface>()"); }
	//bool IsA<class UObject>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UObject>()"); }
	//bool IsA<class UNiagaraDataInterface>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UNiagaraDataInterface>()"); }
	//UNiagaraEmitter* GetTypedOuter<class UNiagaraEmitter>() { return NativeCall<UNiagaraEmitter*>(this, "UObjectBaseUtility.GetTypedOuter<class UNiagaraEmitter>()"); }
	//bool IsA<class UTextureRenderTarget2DArray>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UTextureRenderTarget2DArray>()"); }
	//bool IsA<class UTextureRenderTargetCube>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UTextureRenderTargetCube>()"); }
	//bool IsA<class UTexture>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UTexture>()"); }
	//bool IsA<class UTextureRenderTarget2D>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UTextureRenderTarget2D>()"); }
	//bool IsA<class UTextureRenderTargetVolume>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UTextureRenderTargetVolume>()"); }
	//bool IsA<class UTexture2D>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UTexture2D>()"); }
	//bool IsA<class UStaticMesh>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UStaticMesh>()"); }
	//bool IsA<class UMaterialInstanceDynamic>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMaterialInstanceDynamic>()"); }
	//bool IsA<class UPackage>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPackage>()"); }
	//bool IsA<class UAnimSequence>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UAnimSequence>()"); }
	//bool IsA<class UAnimMontage>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UAnimMontage>()"); }
	//UMovieScene* GetTypedOuter<class UMovieScene>() { return NativeCall<UMovieScene*>(this, "UObjectBaseUtility.GetTypedOuter<class UMovieScene>()"); }
	//UMovieSceneSequence* GetTypedOuter<class UMovieSceneSequence>() { return NativeCall<UMovieSceneSequence*>(this, "UObjectBaseUtility.GetTypedOuter<class UMovieSceneSequence>()"); }
	//bool IsA<class USkinnedMeshComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class USkinnedMeshComponent>()"); }
	//bool IsA<class AVolume>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AVolume>()"); }
	//bool IsA<class UInstancedStaticMeshComponent const>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UInstancedStaticMeshComponent const>()"); }
	//bool IsA<class UBlueprintGeneratedClass>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UBlueprintGeneratedClass>()"); }
	//bool IsA<class USkeletalMesh>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class USkeletalMesh>()"); }
	//bool IsA<class UBlueprint>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UBlueprint>()"); }
	//bool IsA<class UMeshComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMeshComponent>()"); }
	//AActor* GetTypedOuter<class AActor>() { return NativeCall<AActor*>(this, "UObjectBaseUtility.GetTypedOuter<class AActor>()"); }
	//bool IsA<class UActorChannel>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UActorChannel>()"); }
	//bool IsA<class UWorld>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UWorld>()"); }
	//bool IsA<class UMaterial>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMaterial>()"); }
	//bool IsA<class UMaterialInstance>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMaterialInstance>()"); }
	//bool IsA<class USkeleton>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class USkeleton>()"); }
	//USceneComponent* GetTypedOuter<class USceneComponent>() { return NativeCall<USceneComponent*>(this, "UObjectBaseUtility.GetTypedOuter<class USceneComponent>()"); }
	//bool IsA<class UControlRig>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UControlRig>()"); }
	//bool IsA<class UMovieSceneControlRigParameterSection>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMovieSceneControlRigParameterSection>()"); }
	//bool IsA<class UUserDefinedStruct>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UUserDefinedStruct>()"); }
	//UMovieSceneControlRigParameterTrack* GetTypedOuter<class UMovieSceneControlRigParameterTrack>() { return NativeCall<UMovieSceneControlRigParameterTrack*>(this, "UObjectBaseUtility.GetTypedOuter<class UMovieSceneControlRigParameterTrack>()"); }
	//bool IsA<class UTickableConstraint>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UTickableConstraint>()"); }
	//bool IsA<class UGeometryCacheComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UGeometryCacheComponent>()"); }
	//bool IsA<class UOptimusNodeGraph>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UOptimusNodeGraph>()"); }
	//bool IsA<class UMovieSceneSubTrack>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMovieSceneSubTrack>()"); }
	//bool IsA<class UMovieSceneCameraCutSection>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMovieSceneCameraCutSection>()"); }
	//bool IsA<class UMoviePipelineOutputSetting>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMoviePipelineOutputSetting>()"); }
	//bool IsA<class UBoxComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UBoxComponent>()"); }
	//bool IsA<class USphereComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class USphereComponent>()"); }
	//bool IsA<class UPCGParamData>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPCGParamData>()"); }
	//bool IsA<class UPCGPointData>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPCGPointData>()"); }
	//bool IsA<class UPCGGraph>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPCGGraph>()"); }
	//bool IsA<class APlayerController>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APlayerController>()"); }
	//ULevelVariantSets* GetTypedOuter<class ULevelVariantSets>() { return NativeCall<ULevelVariantSets*>(this, "UObjectBaseUtility.GetTypedOuter<class ULevelVariantSets>()"); }
	//UWorld* GetTypedOuter<class UWorld>() { return NativeCall<UWorld*>(this, "UObjectBaseUtility.GetTypedOuter<class UWorld>()"); }
	//bool IsA<class APawn>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APawn>()"); }
	//UActorSequenceComponent* GetTypedOuter<class UActorSequenceComponent>() { return NativeCall<UActorSequenceComponent*>(this, "UObjectBaseUtility.GetTypedOuter<class UActorSequenceComponent>()"); }
	//bool IsA<class UScrollBox>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UScrollBox>()"); }
	//bool IsA<class UButton>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UButton>()"); }
	//bool IsA<class UCheckBox>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UCheckBox>()"); }
	//bool IsA<class UEditableTextBox>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UEditableTextBox>()"); }
	//bool IsA<class APrimalDinoAIController>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalDinoAIController>()"); }
	//bool IsA<class APrimalDinoCharacter>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalDinoCharacter>()"); }
	//bool IsA<class AShooterGameMode>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AShooterGameMode>()"); }
	//bool IsA<class APrimalCharacter>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalCharacter>()"); }
	//bool IsA<class UShooterGameInstance>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UShooterGameInstance>()"); }
	//bool IsA<class APrimalWorldSettings>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalWorldSettings>()"); }
	//bool IsA<class UShooterGameUserSettings>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UShooterGameUserSettings>()"); }
	//bool IsA<class UUserWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UUserWidget>()"); }
	//bool IsA<class AShooterWeapon_Projectile>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AShooterWeapon_Projectile>()"); }
	//bool IsA<class APrimalStructureItemContainer_SupplyCrate>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructureItemContainer_SupplyCrate>()"); }
	//bool IsA<class AShooterCharacter>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AShooterCharacter>()"); }
	//bool IsA<class APrimalBuff_Companion>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalBuff_Companion>()"); }
	//bool IsA<class AShooterPlayerController>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AShooterPlayerController>()"); }
	//bool IsA<class USizeBox>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class USizeBox>()"); }
	//bool IsA<class UTextBlock>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UTextBlock>()"); }
	//bool IsA<class UCustomButtonWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UCustomButtonWidget>()"); }
	//bool IsA<class UWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UWidget>()"); }
	//bool IsA<class UImage>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UImage>()"); }
	//bool IsA<class UDinoListButtonWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UDinoListButtonWidget>()"); }
	//bool IsA<class APhysicsVolume>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APhysicsVolume>()"); }
	//bool IsA<class UDataListPanel>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UDataListPanel>()"); }
	//bool IsA<class APrimalStructure>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructure>()"); }
	//bool IsA<class AShooterProjectile>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AShooterProjectile>()"); }
	//bool IsA<class UPanelWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPanelWidget>()"); }
	//bool IsA<class UProgressBar>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UProgressBar>()"); }
	//bool IsA<class UBorder>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UBorder>()"); }
	//bool IsA<class UPrimalItem>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimalItem>()"); }
	//bool IsA<class AShooterHUD>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AShooterHUD>()"); }
	//bool IsA<class APrimalBuff_MissionData>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalBuff_MissionData>()"); }
	//bool IsA<class UVerticalBox>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UVerticalBox>()"); }
	//bool IsA<class UPrimalUserWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimalUserWidget>()"); }
	//bool IsA<class UPrimalRichTextBlock>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimalRichTextBlock>()"); }
	//bool IsA<class UCanvasPanel>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UCanvasPanel>()"); }
	//bool IsA<class APrimalBuff>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalBuff>()"); }
	//bool IsA<class UProgressBarWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UProgressBarWidget>()"); }
	//bool IsA<class UWidgetSwitcher>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UWidgetSwitcher>()"); }
	//bool IsA<class UTrackedDinoListEntryWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UTrackedDinoListEntryWidget>()"); }
	//bool IsA<class AMissionType>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AMissionType>()"); }
	//bool IsA<class UHorizontalBox>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UHorizontalBox>()"); }
	//bool IsA<class AMissionDispatcher>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AMissionDispatcher>()"); }
	//bool IsA<class ADroppedItemMission>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ADroppedItemMission>()"); }
	//bool IsA<class UNavigationSystemV1>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UNavigationSystemV1>()"); }
	//bool IsA<class UMultiUseActionWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMultiUseActionWidget>()"); }
	//bool IsA<class ADroppedItem>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ADroppedItem>()"); }
	//bool IsA<class AController>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AController>()"); }
	//bool IsA<class UShooterDamageType>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UShooterDamageType>()"); }
	//bool IsA<class UParticleSystemComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UParticleSystemComponent>()"); }
	//bool IsA<class UBlendSpace>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UBlendSpace>()"); }
	//bool IsA<class ULevelStreamingDynamic>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ULevelStreamingDynamic>()"); }
	//bool IsA<class APrimalStructureBed>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructureBed>()"); }
	//bool IsA<class APrimalStructureTripwire>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructureTripwire>()"); }
	//bool IsA<class APrimalStructureItemContainer>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructureItemContainer>()"); }
	//bool IsA<class APrimalStructureExplosive>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructureExplosive>()"); }
	//bool IsA<class AShooterGameState>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AShooterGameState>()"); }
	//bool IsA<class APrimalStructureItemContainer_CropPlot>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructureItemContainer_CropPlot>()"); }
	//bool IsA<class ACustomGameState>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ACustomGameState>()"); }
	//bool IsA<class UPrimalItem_Dye>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimalItem_Dye>()"); }
	//bool IsA<class AShooterPlayerState>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AShooterPlayerState>()"); }
	//bool IsA<class AShooterSpectatorPawn>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AShooterSpectatorPawn>()"); }
	//bool IsA<class AHordeCrateManager>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AHordeCrateManager>()"); }
	//bool IsA<class APrimalFoliageSolver>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalFoliageSolver>()"); }
	//bool IsA<class UPrimalPathFollowingComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimalPathFollowingComponent>()"); }
	//bool IsA<class UPrimalInventoryComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimalInventoryComponent>()"); }
	//bool IsA<class APrimalPawn>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalPawn>()"); }
	//bool IsA<class ANPCZoneManager>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ANPCZoneManager>()"); }
	//bool IsA<class UUI_TribeManager>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UUI_TribeManager>()"); }
	//bool IsA<class UPrimalStaticData_MissionCompanionData>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimalStaticData_MissionCompanionData>()"); }
	//bool IsA<class ABasePlayerController>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ABasePlayerController>()"); }
	//bool IsA<class APrimalTargetableActor>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalTargetableActor>()"); }
	//bool IsA<class UPrimalDinoEntry>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimalDinoEntry>()"); }
	//bool IsA<class UDataListEntryButton_ListSession>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UDataListEntryButton_ListSession>()"); }
	//bool IsA<class UDataListEntryWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UDataListEntryWidget>()"); }
	//bool IsA<class USlider>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class USlider>()"); }
	//bool IsA<class UComboBoxString>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UComboBoxString>()"); }
	//bool IsA<class UMissionBiomeCompletionWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMissionBiomeCompletionWidget>()"); }
	//bool IsA<class UMissionRequirementEntryWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMissionRequirementEntryWidget>()"); }
	//bool IsA<class UMissionTimerWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMissionTimerWidget>()"); }
	//bool IsA<class UUI_PreviewWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UUI_PreviewWidget>()"); }
	//bool IsA<class UGenericDataListEntry>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UGenericDataListEntry>()"); }
	//bool IsA<class UPrimalHarvestingComponent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimalHarvestingComponent>()"); }
	//bool IsA<class UDataListValueGeneric>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UDataListValueGeneric>()"); }
	//bool IsA<class APrimalRaft>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalRaft>()"); }
	//bool IsA<class APrimalStructureDoor>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructureDoor>()"); }
	//bool IsA<class UPrimalEngramEntry>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UPrimalEngramEntry>()"); }
	//bool IsA<class UDataListEntryButton>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UDataListEntryButton>()"); }
	//bool IsA<class UDataListEntryButton_PrimalFolder>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UDataListEntryButton_PrimalFolder>()"); }
	//bool IsA<class UDataListEntryButton_PrimalItem>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UDataListEntryButton_PrimalItem>()"); }
	//bool IsA<class ABiomeZoneVolume>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ABiomeZoneVolume>()"); }
	//bool IsA<class APrimalStructureWaterPipe>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructureWaterPipe>()"); }
	//bool IsA<class APrimalStructureElevatorTrack>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructureElevatorTrack>()"); }
	//bool IsA<class APrimalStructureElevatorPlatform>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalStructureElevatorPlatform>()"); }
	//bool IsA<class UUI_MenuCarousel>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UUI_MenuCarousel>()"); }
	//bool IsA<class UAllPaintingsEntryButton>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UAllPaintingsEntryButton>()"); }
	//bool IsA<class USpawnMapWidget>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class USpawnMapWidget>()"); }
	//bool IsA<class AShooterWeapon_InstantPenetrating>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AShooterWeapon_InstantPenetrating>()"); }
	//bool IsA<class ULinkerPlaceholderClass>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ULinkerPlaceholderClass>()"); }
	//bool IsA<class ULinkerPlaceholderFunction>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ULinkerPlaceholderFunction>()"); }
	//bool IsA<class UFunction>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UFunction>()"); }
	//bool IsA<class UStruct>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UStruct>()"); }
	FPackageFileVersion* GetLinkerUEVersion(FPackageFileVersion* result) { return NativeCall<FPackageFileVersion*, FPackageFileVersion*>(this, "UObjectBaseUtility.GetLinkerUEVersion(FPackageFileVersion*)", result); }
	static __int64 GetLinkerCustomVersion() { return NativeCall<__int64>(nullptr, "UObjectBaseUtility.GetLinkerCustomVersion()"); }
	//bool IsA<class UField>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UField>()"); }
	//UClass* GetTypedOuter<class UClass>() { return NativeCall<UClass*>(this, "UObjectBaseUtility.GetTypedOuter<class UClass>()"); }
	FString* GetPathName(FString* result, const UObject* StopOuter) { return NativeCall<FString*, FString*, const UObject*>(this, "UObjectBaseUtility.GetPathName(FString&,UObject*)", result, StopOuter); }
	void GetPathName(const UObject* StopOuter, FString* ResultString) { NativeCall<void, const UObject*, FString*>(this, "UObjectBaseUtility.GetPathName(UObject*,FString&)", StopOuter, ResultString); }
	void GetPathName(const UObject* StopOuter, TStringBuilderBase<wchar_t>* ResultString) { NativeCall<void, const UObject*, TStringBuilderBase<wchar_t>*>(this, "UObjectBaseUtility.GetPathName(UObject*,TStringBuilderBase<wchar_t>*)", StopOuter, ResultString); }
	//FString* GetFullName(FString* result, const UObject* StopOuter, EObjectFullNameFlags Flags) { return NativeCall<FString*, FString*, const UObject*, EObjectFullNameFlags>(this, "UObjectBaseUtility.GetFullName(FString&,UObject*,EObjectFullNameFlags)", result, StopOuter, Flags); }
	//void GetFullName(const UObject* StopOuter, FString* ResultString, EObjectFullNameFlags Flags) { NativeCall<void, const UObject*, FString*, EObjectFullNameFlags>(this, "UObjectBaseUtility.GetFullName(UObject*,FString&,EObjectFullNameFlags)", StopOuter, ResultString, Flags); }
	FString* GetFullGroupName(FString* result, bool bStartWithOuter) { return NativeCall<FString*, FString*, bool>(this, "UObjectBaseUtility.GetFullGroupName(FString&,bool)", result, bStartWithOuter); }
	UObject* GetOutermostObject() { return NativeCall<UObject*>(this, "UObjectBaseUtility.GetOutermostObject()"); }
	UPackage* GetPackage() { return NativeCall<UPackage*>(this, "UObjectBaseUtility.GetPackage()"); }
	bool MarkPackageDirty() { return NativeCall<bool>(this, "UObjectBaseUtility.MarkPackageDirty()"); }
	//bool IsTemplate(EObjectFlags TemplateTypes) { return NativeCall<bool, EObjectFlags>(this, "UObjectBaseUtility.IsTemplate(EObjectFlags)", TemplateTypes); }
	UObject* GetTypedOuter(UClass* Target) { return NativeCall<UObject*, UClass*>(this, "UObjectBaseUtility.GetTypedOuter(UClass*)", Target); }
	bool IsIn(const UObject* SomeOuter) { return NativeCall<bool, const UObject*>(this, "UObjectBaseUtility.IsIn(UObject*)", SomeOuter); }
	bool IsInPackage(const UPackage* SomePackage) { return NativeCall<bool, const UPackage*>(this, "UObjectBaseUtility.IsInPackage(UPackage*)", SomePackage); }
	void* GetInterfaceAddress(UClass* InterfaceClass) { return NativeCall<void*, UClass*>(this, "UObjectBaseUtility.GetInterfaceAddress(UClass*)", InterfaceClass); }
	bool IsDefaultSubobject() { return NativeCall<bool>(this, "UObjectBaseUtility.IsDefaultSubobject()"); }
	void AddToCluster(UObjectBaseUtility* ClusterRootOrObjectFromCluster, bool bAddAsMutableObject) { NativeCall<void, UObjectBaseUtility*, bool>(this, "UObjectBaseUtility.AddToCluster(UObjectBaseUtility*,bool)", ClusterRootOrObjectFromCluster, bAddAsMutableObject); }
	bool CanBeInCluster() { return NativeCall<bool>(this, "UObjectBaseUtility.CanBeInCluster()"); }
	void CreateCluster() { NativeCall<void>(this, "UObjectBaseUtility.CreateCluster()"); }
	FLinkerLoad* GetLinker() { return NativeCall<FLinkerLoad*>(this, "UObjectBaseUtility.GetLinker()"); }
	int GetLinkerIndex() { return NativeCall<int>(this, "UObjectBaseUtility.GetLinkerIndex()"); }
	//UMovieSceneTrack* GetTypedOuter<class UMovieSceneTrack>() { return NativeCall<UMovieSceneTrack*>(this, "UObjectBaseUtility.GetTypedOuter<class UMovieSceneTrack>()"); }
	//IMovieSceneBlenderSystemSupport* GetImplementingOuter<class IMovieSceneBlenderSystemSupport>() { return NativeCall<IMovieSceneBlenderSystemSupport*>(this, "UObjectBaseUtility.GetImplementingOuter<class IMovieSceneBlenderSystemSupport>()"); }
	//UMovieScenePropertyTrack* GetTypedOuter<class UMovieScenePropertyTrack>() { return NativeCall<UMovieScenePropertyTrack*>(this, "UObjectBaseUtility.GetTypedOuter<class UMovieScenePropertyTrack>()"); }
	//UMovieSceneEventTrack* GetTypedOuter<class UMovieSceneEventTrack>() { return NativeCall<UMovieSceneEventTrack*>(this, "UObjectBaseUtility.GetTypedOuter<class UMovieSceneEventTrack>()"); }
	//UMovieSceneSkeletalAnimationTrack* GetTypedOuter<class UMovieSceneSkeletalAnimationTrack>() { return NativeCall<UMovieSceneSkeletalAnimationTrack*>(this, "UObjectBaseUtility.GetTypedOuter<class UMovieSceneSkeletalAnimationTrack>()"); }
	//bool IsA<class ALevelScriptActor>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ALevelScriptActor>()"); }
	//bool IsA<class UMaterialParameterCollectionInstance>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class UMaterialParameterCollectionInstance>()"); }
	//UMovieScene2DTransformTrack* GetTypedOuter<class UMovieScene2DTransformTrack>() { return NativeCall<UMovieScene2DTransformTrack*>(this, "UObjectBaseUtility.GetTypedOuter<class UMovieScene2DTransformTrack>()"); }
	//UUserWidget* GetTypedOuter<class UUserWidget>() { return NativeCall<UUserWidget*>(this, "UObjectBaseUtility.GetTypedOuter<class UUserWidget>()"); }
	//ULevel* GetTypedOuter<class ULevel>() { return NativeCall<ULevel*>(this, "UObjectBaseUtility.GetTypedOuter<class ULevel>()"); }
	//bool IsA<class APrimalGameMode>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class APrimalGameMode>()"); }
	//bool IsA<class ULevelStreamingPersistent>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class ULevelStreamingPersistent>()"); }
	//bool IsA<class AWorldSettings>() { return NativeCall<bool>(this, "UObjectBaseUtility.IsA<class AWorldSettings>()"); }
};

struct UObject : UObjectBaseUtility
{
	// Fields


	  // Bitfields


	  // Functions

	bool ProcessConsoleExec(const wchar_t* Cmd, FOutputDevice* Ar, UObject* Executor) { return NativeCall<bool, const wchar_t*, FOutputDevice*, UObject*>(this, "UObject.ProcessConsoleExec(wchar_t*,FOutputDevice*,UObject*)", Cmd, Ar, Executor); }
	FString* GetDetailedInfoInternal(FString* result) { return NativeCall<FString*, FString*>(this, "UObject.GetDetailedInfoInternal(FString&)", result); }
	//void ~UObject() { NativeCall<void>(this, "UObject.~UObject()"); }
	static UClass* StaticClass() { return NativeCall<UClass*>(nullptr, "UObject.StaticClass()"); }
	//unsigned __int64 GetResourceSizeBytes(EResourceSizeMode::Type Mode) { return NativeCall<unsigned __int64, EResourceSizeMode::Type>(this, "UObject.GetResourceSizeBytes(EResourceSizeMode::Type)", Mode); }
	bool AreAllOuterObjectsValid() { return NativeCall<bool>(this, "UObject.AreAllOuterObjectsValid()"); }
	bool IsInBlueprint() { return NativeCall<bool>(this, "UObject.IsInBlueprint()"); }
	bool IsBasedOnArchetype(const UObject* const SomeObject) { return NativeCall<bool, const UObject* const>(this, "UObject.IsBasedOnArchetype(UObject*const)", SomeObject); }
	UObject* CreateDefaultSubobject(FName SubobjectFName, UClass* ReturnType, UClass* ClassToCreateByDefault, bool bIsRequired, bool bIsTransient) { return NativeCall<UObject*, FName, UClass*, UClass*, bool, bool>(this, "UObject.CreateDefaultSubobject(FName,UClass*,UClass*,bool,bool)", SubobjectFName, ReturnType, ClassToCreateByDefault, bIsRequired, bIsTransient); }
	UObject* GetDefaultSubobjectByName(FName ToFind) { return NativeCall<UObject*, FName>(this, "UObject.GetDefaultSubobjectByName(FName)", ToFind); }
	bool Rename(const wchar_t* InName, UObject* NewOuter, unsigned int Flags) { return NativeCall<bool, const wchar_t*, UObject*, unsigned int>(this, "UObject.Rename(wchar_t*,UObject*,unsignedint)", InName, NewOuter, Flags); }
	void PostLoad() { NativeCall<void>(this, "UObject.PostLoad()"); }
	bool NeedsLoadForServer() { return NativeCall<bool>(this, "UObject.NeedsLoadForServer()"); }
	bool NeedsLoadForClient() { return NativeCall<bool>(this, "UObject.NeedsLoadForClient()"); }
	void BeginDestroy() { NativeCall<void>(this, "UObject.BeginDestroy()"); }
	void FinishDestroy() { NativeCall<void>(this, "UObject.FinishDestroy()"); }
	FString* GetDetailedInfo(FString* result) { return NativeCall<FString*, FString*>(this, "UObject.GetDetailedInfo(FString&)", result); }
	bool ConditionalBeginDestroy() { return NativeCall<bool>(this, "UObject.ConditionalBeginDestroy()"); }
	bool ConditionalFinishDestroy() { return NativeCall<bool>(this, "UObject.ConditionalFinishDestroy()"); }
	void ConditionalPostLoad() { NativeCall<void>(this, "UObject.ConditionalPostLoad()"); }
	void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) { NativeCall<void, FObjectInstancingGraph*>(this, "UObject.PostLoadSubobjects(FObjectInstancingGraph*)", OuterInstanceGraph); }
	void ConditionalPostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) { NativeCall<void, FObjectInstancingGraph*>(this, "UObject.ConditionalPostLoadSubobjects(FObjectInstancingGraph*)", OuterInstanceGraph); }
	//void PreSave(FObjectPreSaveContext SaveContext) { NativeCall<void, FObjectPreSaveContext>(this, "UObject.PreSave(FObjectPreSaveContext)", SaveContext); }
	void GetPreloadDependencies(TArray<UObject*, TSizedDefaultAllocator<32> >* OutDeps) { NativeCall<void, TArray<UObject*, TSizedDefaultAllocator<32> >*>(this, "UObject.GetPreloadDependencies(TArray<UObject*,TSizedDefaultAllocator<32>>*)", OutDeps); }
	void Serialize(FStructuredArchiveRecord Record) { NativeCall<void, FStructuredArchiveRecord>(this, "UObject.Serialize(FStructuredArchiveRecord)", Record); }
	void SerializeScriptProperties(FArchive* Ar) { NativeCall<void, FArchive*>(this, "UObject.SerializeScriptProperties(FArchive*)", Ar); }
	void SerializeScriptProperties(FStructuredArchiveSlot Slot) { NativeCall<void, FStructuredArchiveSlot>(this, "UObject.SerializeScriptProperties(FStructuredArchiveSlot)", Slot); }
	void BuildSubobjectMapping(UObject* OtherObject, TMap<UObject*, UObject*, FDefaultSetAllocator, TDefaultMapHashableKeyFuncs<UObject*, UObject*, 0> >* ObjectMapping) { NativeCall<void, UObject*, TMap<UObject*, UObject*, FDefaultSetAllocator, TDefaultMapHashableKeyFuncs<UObject*, UObject*, 0> >*>(this, "UObject.BuildSubobjectMapping(UObject*,TMap<UObject*,UObject*,FDefaultSetAllocator,TDefaultMapHashableKeyFuncs<UObject*,UObject*,0>>*)", OtherObject, ObjectMapping); }
	void CollectDefaultSubobjects(TArray<UObject*, TSizedDefaultAllocator<32> >* OutSubobjectArray, bool bIncludeNestedSubobjects) { NativeCall<void, TArray<UObject*, TSizedDefaultAllocator<32> >*, bool>(this, "UObject.CollectDefaultSubobjects(TArray<UObject*,TSizedDefaultAllocator<32>>*,bool)", OutSubobjectArray, bIncludeNestedSubobjects); }
	bool CheckDefaultSubobjects(bool bForceCheck) { return NativeCall<bool, bool>(this, "UObject.CheckDefaultSubobjects(bool)", bForceCheck); }
	bool CheckDefaultSubobjectsInternal() { return NativeCall<bool>(this, "UObject.CheckDefaultSubobjectsInternal()"); }
	//void GetAssetRegistryTags(TArray<UObject::FAssetRegistryTag, TSizedDefaultAllocator<32> >* OutTags) { NativeCall<void, TArray<UObject::FAssetRegistryTag, TSizedDefaultAllocator<32> >*>(this, "UObject.GetAssetRegistryTags(TArray<UObject::FAssetRegistryTag,TSizedDefaultAllocator<32>>*)", OutTags); }
	void GetAssetRegistryTags(FAssetData* Out) { NativeCall<void, FAssetData*>(this, "UObject.GetAssetRegistryTags(FAssetData*)", Out); }
	static const FName* AssetVersePathTagName() { return NativeCall<const FName*>(nullptr, "UObject.AssetVersePathTagName()"); }
	void GetResourceSizeEx(FResourceSizeEx* CumulativeResourceSize) { NativeCall<void, FResourceSizeEx*>(this, "UObject.GetResourceSizeEx(FResourceSizeEx*)", CumulativeResourceSize); }
	bool IsAsset() { return NativeCall<bool>(this, "UObject.IsAsset()"); }
	FPrimaryAssetId* GetPrimaryAssetId(FPrimaryAssetId* result) { return NativeCall<FPrimaryAssetId*, FPrimaryAssetId*>(this, "UObject.GetPrimaryAssetId(FPrimaryAssetId*)", result); }
	bool IsLocalizedResource() { return NativeCall<bool>(this, "UObject.IsLocalizedResource()"); }
	bool IsSafeForRootSet() { return NativeCall<bool>(this, "UObject.IsSafeForRootSet()"); }
	//void TagSubobjects(EObjectFlags NewFlags) { NativeCall<void, EObjectFlags>(this, "UObject.TagSubobjects(EObjectFlags)", NewFlags); }
	void LoadConfig(UClass* ConfigClass, const wchar_t* InFilename, unsigned int PropagationFlags, FProperty* PropertyToLoad) { NativeCall<void, UClass*, const wchar_t*, unsigned int, FProperty*>(this, "UObject.LoadConfig(UClass*,wchar_t*,unsignedint,FProperty*)", ConfigClass, InFilename, PropagationFlags, PropertyToLoad); }
	void SaveConfig(unsigned __int64 Flags, const wchar_t* InFilename, FConfigCacheIni* Config, bool bAllowCopyToDefaultObject) { NativeCall<void, unsigned __int64, const wchar_t*, FConfigCacheIni*, bool>(this, "UObject.SaveConfig(unsigned__int64,wchar_t*,FConfigCacheIni*,bool)", Flags, InFilename, Config, bAllowCopyToDefaultObject); }
	FString* GetDefaultConfigFilename(FString* result) { return NativeCall<FString*, FString*>(this, "UObject.GetDefaultConfigFilename(FString&)", result); }
	bool IsNameStableForNetworking() { return NativeCall<bool>(this, "UObject.IsNameStableForNetworking()"); }
	bool IsFullNameStableForNetworking() { return NativeCall<bool>(this, "UObject.IsFullNameStableForNetworking()"); }
	bool IsSupportedForNetworking() { return NativeCall<bool>(this, "UObject.IsSupportedForNetworking()"); }
	void LocalizeProperty(UObject* LocBase, TArray<FString, TSizedDefaultAllocator<32> >* PropertyTagChain, FProperty* const BaseProperty, FProperty* const Property, void* const ValueAddress) { NativeCall<void, UObject*, TArray<FString, TSizedDefaultAllocator<32> >*, FProperty* const, FProperty* const, void* const>(this, "UObject.LocalizeProperty(UObject*,TArray<FString,TSizedDefaultAllocator<32>>*,FProperty*const,FProperty*const,void*const)", LocBase, PropertyTagChain, BaseProperty, Property, ValueAddress); }
	void SkipFunction(FFrame* Stack, void* const Z_Param__Result, UFunction* Function) { NativeCall<void, FFrame*, void* const, UFunction*>(this, "UObject.SkipFunction(FFrame*,void*const,UFunction*)", Stack, Z_Param__Result, Function); }
	void CallFunction(FFrame* Stack, void* const Z_Param__Result, UFunction* Function) { NativeCall<void, FFrame*, void* const, UFunction*>(this, "UObject.CallFunction(FFrame*,void*const,UFunction*)", Stack, Z_Param__Result, Function); }
	static void ProcessInternal(UObject* Context, FFrame* Stack, void* const Z_Param__Result) { NativeCall<void, UObject*, FFrame*, void* const>(nullptr, "UObject.ProcessInternal(UObject*,FFrame*,void*const)", Context, Stack, Z_Param__Result); }
	bool CallFunctionByNameWithArguments(const wchar_t* Str, FOutputDevice* Ar, UObject* Executor, bool bForceCallWithNonExec) { return NativeCall<bool, const wchar_t*, FOutputDevice*, UObject*, bool>(this, "UObject.CallFunctionByNameWithArguments(wchar_t*,FOutputDevice*,UObject*,bool)", Str, Ar, Executor, bForceCallWithNonExec); }
	UFunction* FindFunctionChecked(FName InName) { return NativeCall<UFunction*, FName>(this, "UObject.FindFunctionChecked(FName)", InName); }
	void ProcessEvent(UFunction* Function, void* Parms) { NativeCall<void, UFunction*, void*>(this, "UObject.ProcessEvent(UFunction*,void*)", Function, Parms); }
	void ProcessContextOpcode(FFrame* Stack, void* const Z_Param__Result, bool bCanFailSilently) { NativeCall<void, FFrame*, void* const, bool>(this, "UObject.ProcessContextOpcode(FFrame*,void*const,bool)", Stack, Z_Param__Result, bCanFailSilently); }
	//void execIntZero(FBehaviorTreeSearchData* SearchData, EBTNodeResult::Type* NodeResult) { NativeCall<void, FBehaviorTreeSearchData*, EBTNodeResult::Type*>(this, "UObject.execIntZero(FBehaviorTreeSearchData*,EBTNodeResult::Type*)", SearchData, NodeResult); }
	UObject* GetArchetype() { return NativeCall<UObject*>(this, "UObject.GetArchetype()"); }
	bool IsInOrOwnedBy(const UObject* SomeOuter) { return NativeCall<bool, const UObject*>(this, "UObject.IsInOrOwnedBy(UObject*)", SomeOuter); }
	//void UObject() { NativeCall<void>(this, "UObject.UObject()"); }
	void SetLinker(FLinkerLoad* LinkerLoad, int LinkerIndex, bool bShouldDetachExisting) { NativeCall<void, FLinkerLoad*, int, bool>(this, "UObject.SetLinker(FLinkerLoad*,int,bool)", LinkerLoad, LinkerIndex, bShouldDetachExisting); }
};

struct UStreamableRenderAsset : UObject
{
	// Fields

	//TArray<UStreamableRenderAsset::FLODStreamingCallbackPayload, TSizedDefaultAllocator<32> >& MipChangeCallbacksField() { return *GetNativePointerField<TArray<UStreamableRenderAsset::FLODStreamingCallbackPayload, TSizedDefaultAllocator<32> >*>(this, "UStreamableRenderAsset.MipChangeCallbacks"); }
	//TRefCountPtr<FRenderAssetUpdate>& PendingUpdateField() { return *GetNativePointerField<TRefCountPtr<FRenderAssetUpdate>*>(this, "UStreamableRenderAsset.PendingUpdate"); }
	long double& ForceMipLevelsToBeResidentTimestampField() { return *GetNativePointerField<long double*>(this, "UStreamableRenderAsset.ForceMipLevelsToBeResidentTimestamp"); }
	int& NumCinematicMipLevelsField() { return *GetNativePointerField<int*>(this, "UStreamableRenderAsset.NumCinematicMipLevels"); }
	//FPerQualityLevelInt& NoRefStreamingLODBiasField() { return *GetNativePointerField<FPerQualityLevelInt*>(this, "UStreamableRenderAsset.NoRefStreamingLODBias"); }
	int& StreamingIndexField() { return *GetNativePointerField<int*>(this, "UStreamableRenderAsset.StreamingIndex"); }
	//FStreamableRenderResourceState& CachedSRRStateField() { return *GetNativePointerField<FStreamableRenderResourceState*>(this, "UStreamableRenderAsset.CachedSRRState"); }

	// Bitfields

	BitFieldValue<bool, unsigned __int32> NeverStream() { return { this, "UStreamableRenderAsset.NeverStream" }; }
	BitFieldValue<bool, unsigned __int32> bGlobalForceMipLevelsToBeResident() { return { this, "UStreamableRenderAsset.bGlobalForceMipLevelsToBeResident" }; }
	BitFieldValue<bool, unsigned __int32> bHasStreamingUpdatePending() { return { this, "UStreamableRenderAsset.bHasStreamingUpdatePending" }; }
	BitFieldValue<bool, unsigned __int32> bForceMiplevelsToBeResident() { return { this, "UStreamableRenderAsset.bForceMiplevelsToBeResident" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreStreamingMipBias() { return { this, "UStreamableRenderAsset.bIgnoreStreamingMipBias" }; }
	BitFieldValue<bool, unsigned __int32> bUseCinematicMipLevels() { return { this, "UStreamableRenderAsset.bUseCinematicMipLevels" }; }

	// Functions

	void ResizeGrow(int OldNum) { NativeCall<void, int>(this, "UStreamableRenderAsset.ResizeGrow(int)", OldNum); }
	bool StreamIn(int NewMipCount, bool bHighPrio) { return NativeCall<bool, int, bool>(this, "UStreamableRenderAsset.StreamIn(int,bool)", NewMipCount, bHighPrio); }
	bool StreamOut(int NewMipCount) { return NativeCall<bool, int>(this, "UStreamableRenderAsset.StreamOut(int)", NewMipCount); }
	int CalcCumulativeLODSize(int NumLODs) { return NativeCall<int, int>(this, "UStreamableRenderAsset.CalcCumulativeLODSize(int)", NumLODs); }
	bool ShouldMipLevelsBeForcedResident() { return NativeCall<bool>(this, "UStreamableRenderAsset.ShouldMipLevelsBeForcedResident()"); }
	float GetLastRenderTimeForStreaming() { return NativeCall<float>(this, "UStreamableRenderAsset.GetLastRenderTimeForStreaming()"); }
	bool DoesMipDataExist(const int MipIndex) { return NativeCall<bool, const int>(this, "UStreamableRenderAsset.DoesMipDataExist(int)", MipIndex); }
	unsigned int GetMipIoFilenameHash(const int MipIndex) { return NativeCall<unsigned int, const int>(this, "UStreamableRenderAsset.GetMipIoFilenameHash(int)", MipIndex); }
	static UClass* StaticClass() { return NativeCall<UClass*>(nullptr, "UStreamableRenderAsset.StaticClass()"); }
	static void StaticRegisterNativesUStreamableRenderAsset() { NativeCall<void>(nullptr, "UStreamableRenderAsset.StaticRegisterNativesUStreamableRenderAsset()"); }
	//void UStreamableRenderAsset(const FObjectInitializer* ObjectInitializer) { NativeCall<void, const FObjectInitializer*>(this, "UStreamableRenderAsset.UStreamableRenderAsset(FObjectInitializer*)", ObjectInitializer); }
	//void ~UStreamableRenderAsset() { NativeCall<void>(this, "UStreamableRenderAsset.~UStreamableRenderAsset()"); }
	void TickMipLevelChangeCallbacks(TArray<UStreamableRenderAsset*, TSizedDefaultAllocator<32> >* DeferredTickCBAssets) { NativeCall<void, TArray<UStreamableRenderAsset*, TSizedDefaultAllocator<32> >*>(this, "UStreamableRenderAsset.TickMipLevelChangeCallbacks(TArray<UStreamableRenderAsset*,TSizedDefaultAllocator<32>>*)", DeferredTickCBAssets); }
	void TickStreaming(bool bSendCompletionEvents, TArray<UStreamableRenderAsset*, TSizedDefaultAllocator<32> >* DeferredTickCBAssets) { NativeCall<void, bool, TArray<UStreamableRenderAsset*, TSizedDefaultAllocator<32> >*>(this, "UStreamableRenderAsset.TickStreaming(bool,TArray<UStreamableRenderAsset*,TSizedDefaultAllocator<32>>*)", bSendCompletionEvents, DeferredTickCBAssets); }
	void SetForceMipLevelsToBeResident(float Seconds, int CinematicLODGroupMask) { NativeCall<void, float, int>(this, "UStreamableRenderAsset.SetForceMipLevelsToBeResident(float,int)", Seconds, CinematicLODGroupMask); }
	bool HasPendingInitOrStreaming(bool bWaitForLODTransition) { return NativeCall<bool, bool>(this, "UStreamableRenderAsset.HasPendingInitOrStreaming(bool)", bWaitForLODTransition); }
	void LinkStreaming() { NativeCall<void>(this, "UStreamableRenderAsset.LinkStreaming()"); }
	void UnlinkStreaming() { NativeCall<void>(this, "UStreamableRenderAsset.UnlinkStreaming()"); }
	void WaitForPendingInitOrStreaming(bool bWaitForLODTransition, bool bSendCompletionEvents) { NativeCall<void, bool, bool>(this, "UStreamableRenderAsset.WaitForPendingInitOrStreaming(bool,bool)", bWaitForLODTransition, bSendCompletionEvents); }
	void BeginDestroy() { NativeCall<void>(this, "UStreamableRenderAsset.BeginDestroy()"); }
	bool IsReadyForFinishDestroy() { return NativeCall<bool>(this, "UStreamableRenderAsset.IsReadyForFinishDestroy()"); }
	//void FLODStreamingCallbackPayload, class TSizedDefaultAllocator<32 >> () { NativeCall<void>(this, "UStreamableRenderAsset.FLODStreamingCallbackPayload,class TSizedDefaultAllocator<32>>()"); }
	void RemoveAtSwapImpl(int Index, int Count, bool bAllowShrinking) { NativeCall<void, int, int, bool>(this, "UStreamableRenderAsset.RemoveAtSwapImpl(int,int,bool)", Index, Count, bAllowShrinking); }
	void RemoveAtImpl(int Index, int Count, bool bAllowShrinking) { NativeCall<void, int, int, bool>(this, "UStreamableRenderAsset.RemoveAtImpl(int,int,bool)", Index, Count, bAllowShrinking); }
};

struct UTexture : UStreamableRenderAsset
{
	// Fields

	FGuid& LightingGuidField() { return *GetNativePointerField<FGuid*>(this, "UTexture.LightingGuid"); }
	int& LevelIndexField() { return *GetNativePointerField<int*>(this, "UTexture.LevelIndex"); }
	//FPerPlatformInt& LODBiasField() { return *GetNativePointerField<FPerPlatformInt*>(this, "UTexture.LODBias"); }
	TEnumAsByte<enum TextureFilter>& FilterField() { return *GetNativePointerField<TEnumAsByte<enum TextureFilter>*>(this, "UTexture.Filter"); }
	TEnumAsByte<enum TextureCookPlatformTilingSettings>& CookPlatformTilingSettingsField() { return *GetNativePointerField<TEnumAsByte<enum TextureCookPlatformTilingSettings>*>(this, "UTexture.CookPlatformTilingSettings"); }
	//FPerPlatformFloat& DownscaleField() { return *GetNativePointerField<FPerPlatformFloat*>(this, "UTexture.Downscale"); }
	//TArray<TObjectPtr<UAssetUserData>, TSizedDefaultAllocator<32> >& AssetUserDataField() { return *GetNativePointerField<TArray<TObjectPtr<UAssetUserData>, TSizedDefaultAllocator<32> >*>(this, "UTexture.AssetUserData"); }
	//FTextureResource*& PrivateResourceField() { return *GetNativePointerField<FTextureResource**>(this, "UTexture.PrivateResource"); }
	//FTextureResource*& PrivateResourceRenderThreadField() { return *GetNativePointerField<FTextureResource**>(this, "UTexture.PrivateResourceRenderThread"); }
	//FTextureResource*& PrivateResourceToDeleteField() { return *GetNativePointerField<FTextureResource**>(this, "UTexture.PrivateResourceToDelete"); }
	//TFieldPtrAccessor<FTextureResource>& ResourceField() { return *GetNativePointerField<TFieldPtrAccessor<FTextureResource>*>(this, "UTexture.Resource"); }
	//FTextureReference*& TextureReferenceField() { return *GetNativePointerField<FTextureReference**>(this, "UTexture.TextureReference"); }
	FRenderCommandFence& ReleaseFenceField() { return *GetNativePointerField<FRenderCommandFence*>(this, "UTexture.ReleaseFence"); }

	// Bitfields

	BitFieldValue<bool, unsigned __int32> SRGB() { return { this, "UTexture.SRGB" }; }
	BitFieldValue<bool, unsigned __int32> bNoTiling() { return { this, "UTexture.bNoTiling" }; }
	BitFieldValue<bool, unsigned __int32> VirtualTextureStreaming() { return { this, "UTexture.VirtualTextureStreaming" }; }
	BitFieldValue<bool, unsigned __int32> CompressionYCoCg() { return { this, "UTexture.CompressionYCoCg" }; }
	BitFieldValue<bool, unsigned __int32> bNotOfflineProcessed() { return { this, "UTexture.bNotOfflineProcessed" }; }
	BitFieldValue<bool, unsigned __int32> bAsyncResourceReleaseHasBeenStarted() { return { this, "UTexture.bAsyncResourceReleaseHasBeenStarted" }; }

	// Functions

	static UClass* GetPrivateStaticClass() { return NativeCall<UClass*>(nullptr, "UTexture.GetPrivateStaticClass()"); }
	const FString* GetAssetUserDataArray() { return NativeCall<const FString*>(this, "UTexture.GetAssetUserDataArray()"); }
	//EMaterialValueType GetMaterialType() { return NativeCall<EMaterialValueType>(this, "UTexture.GetMaterialType()"); }
	//FTextureResource* CreateResource() { return NativeCall<FTextureResource*>(this, "UTexture.CreateResource()"); }
	int GetCachedLODBias() { return NativeCall<int>(this, "UTexture.GetCachedLODBias()"); }
	static void StaticRegisterNativesUTexture() { NativeCall<void>(nullptr, "UTexture.StaticRegisterNativesUTexture()"); }
	void Serialize(FStructuredArchiveRecord Record) { NativeCall<void, FStructuredArchiveRecord>(this, "UTexture.Serialize(FStructuredArchiveRecord)", Record); }
	//void UTexture(const FObjectInitializer* ObjectInitializer) { NativeCall<void, const FObjectInitializer*>(this, "UTexture.UTexture(FObjectInitializer*)", ObjectInitializer); }
	//const FTextureResource* GetResource() { return NativeCall<const FTextureResource*>(this, "UTexture.GetResource()"); }
	//void ~UTexture() { NativeCall<void>(this, "UTexture.~UTexture()"); }
	void ReleaseResource() { NativeCall<void>(this, "UTexture.ReleaseResource()"); }
	void Serialize(FArchive* Ar) { NativeCall<void, FArchive*>(this, "UTexture.Serialize(FArchive*)", Ar); }
	void PostLoad() { NativeCall<void>(this, "UTexture.PostLoad()"); }
	void BeginFinalReleaseResource() { NativeCall<void>(this, "UTexture.BeginFinalReleaseResource()"); }
	void BeginDestroy() { NativeCall<void>(this, "UTexture.BeginDestroy()"); }
	bool IsReadyForFinishDestroy() { return NativeCall<bool>(this, "UTexture.IsReadyForFinishDestroy()"); }
	void FinishDestroy() { NativeCall<void>(this, "UTexture.FinishDestroy()"); }
	//void PreSave(FObjectPreSaveContext ObjectSaveContext) { NativeCall<void, FObjectPreSaveContext>(this, "UTexture.PreSave(FObjectPreSaveContext)", ObjectSaveContext); }
	unsigned int GetMipIoFilenameHash(const int MipIndex) { return NativeCall<unsigned int, const int>(this, "UTexture.GetMipIoFilenameHash(int)", MipIndex); }
	bool DoesMipDataExist(const int MipIndex) { return NativeCall<bool, const int>(this, "UTexture.DoesMipDataExist(int)", MipIndex); }
	bool HasPendingRenderResourceInitialization() { return NativeCall<bool>(this, "UTexture.HasPendingRenderResourceInitialization()"); }
	bool HasPendingLODTransition() { return NativeCall<bool>(this, "UTexture.HasPendingLODTransition()"); }
	float GetLastRenderTimeForStreaming() { return NativeCall<float>(this, "UTexture.GetLastRenderTimeForStreaming()"); }
	void InvalidateLastRenderTimeForStreaming() { NativeCall<void>(this, "UTexture.InvalidateLastRenderTimeForStreaming()"); }
	bool ShouldMipLevelsBeForcedResident() { return NativeCall<bool>(this, "UTexture.ShouldMipLevelsBeForcedResident()"); }
	static void CancelPendingTextureStreaming() { NativeCall<void>(nullptr, "UTexture.CancelPendingTextureStreaming()"); }
	//static const wchar_t* GetTextureGroupString(TextureGroup InGroup) { return NativeCall<const wchar_t*, TextureGroup>(nullptr, "UTexture.GetTextureGroupString(TextureGroup)", InGroup); }
	static UEnum* GetPixelFormatEnum() { return NativeCall<UEnum*>(nullptr, "UTexture.GetPixelFormatEnum()"); }
	void PostCDOContruct() { NativeCall<void>(this, "UTexture.PostCDOContruct()"); }
	//void AddAssetUserData(UAssetUserData* InUserData) { NativeCall<void, UAssetUserData*>(this, "UTexture.AddAssetUserData(UAssetUserData*)", InUserData); }
	//UAssetUserData* GetAssetUserDataOfClass(TSubclassOf<UAssetUserData> InUserDataClass) { return NativeCall<UAssetUserData*, TSubclassOf<UAssetUserData>>(this, "UTexture.GetAssetUserDataOfClass(TSubclassOf<UAssetUserData>)", InUserDataClass); }
	//void RemoveUserDataOfClass(TSubclassOf<UAssetUserData> InUserDataClass) { NativeCall<void, TSubclassOf<UAssetUserData>>(this, "UTexture.RemoveUserDataOfClass(TSubclassOf<UAssetUserData>)", InUserDataClass); }
	//FStreamableRenderResourceState* GetResourcePostInitState(FStreamableRenderResourceState* result, const FTexturePlatformData* PlatformData, bool bAllowStreaming, int MinRequestMipCount, int MaxMipCount, bool bSkipCanBeLoaded) { return NativeCall<FStreamableRenderResourceState*, FStreamableRenderResourceState*, const FTexturePlatformData*, bool, int, int, bool>(this, "UTexture.GetResourcePostInitState(FStreamableRenderResourceState*,FTexturePlatformData*,bool,int,int,bool)", result, PlatformData, bAllowStreaming, MinRequestMipCount, MaxMipCount, bSkipCanBeLoaded); }
	//void GetVirtualTextureBuildSettings(FVirtualTextureBuildSettings* OutSettings) { NativeCall<void, FVirtualTextureBuildSettings*>(this, "UTexture.GetVirtualTextureBuildSettings(FVirtualTextureBuildSettings*)", OutSettings); }
	void SerializeCookedPlatformData(FArchive* Ar) { NativeCall<void, FArchive*>(this, "UTexture.SerializeCookedPlatformData(FArchive*)", Ar); }
	unsigned int GetSurfaceArraySize() { return NativeCall<unsigned int>(this, "UTexture.GetSurfaceArraySize()"); }
	float GetSurfaceDepth() { return NativeCall<float>(this, "UTexture.GetSurfaceDepth()"); }
	float GetSurfaceHeight() { return NativeCall<float>(this, "UTexture.GetSurfaceHeight()"); }
	float GetSurfaceWidth() { return NativeCall<float>(this, "UTexture.GetSurfaceWidth()"); }
	//ETextureClass GetTextureClass() { return NativeCall<ETextureClass>(this, "UTexture.GetTextureClass()"); }
};

struct UTexture2D : UTexture
{
	// Fields

	UE::Math::TIntPoint<int>& ImportedSizeField() { return *GetNativePointerField<UE::Math::TIntPoint<int>*>(this, "UTexture2D.ImportedSize"); }
	//FTexturePlatformData*& PrivatePlatformDataField() { return *GetNativePointerField<FTexturePlatformData**>(this, "UTexture2D.PrivatePlatformData"); }
	//TFieldPtrAccessor<FTexturePlatformData>& PlatformDataField() { return *GetNativePointerField<TFieldPtrAccessor<FTexturePlatformData>*>(this, "UTexture2D.PlatformData"); }
	//FTexture2DResourceMem*& ResourceMemField() { return *GetNativePointerField<FTexture2DResourceMem**>(this, "UTexture2D.ResourceMem"); }

	// Bitfields


	// Functions

	static UClass* GetPrivateStaticClass() { return NativeCall<UClass*>(nullptr, "UTexture2D.GetPrivateStaticClass()"); }
	//TextureAddress GetTextureAddressY() { return NativeCall<TextureAddress>(this, "UTexture2D.GetTextureAddressY()"); }
	//TextureAddress GetTextureAddressX() { return NativeCall<TextureAddress>(this, "UTexture2D.GetTextureAddressX()"); }
	float GetSurfaceHeight() { return NativeCall<float>(this, "UTexture2D.GetSurfaceHeight()"); }
	float GetSurfaceWidth() { return NativeCall<float>(this, "UTexture2D.GetSurfaceWidth()"); }
	int CalcCumulativeLODSize(int NumLODs) { return NativeCall<int, int>(this, "UTexture2D.CalcCumulativeLODSize(int)", NumLODs); }
	static void StaticRegisterNativesUTexture2D() { NativeCall<void>(nullptr, "UTexture2D.StaticRegisterNativesUTexture2D()"); }
	//void ~UTexture2D() { NativeCall<void>(this, "UTexture2D.~UTexture2D()"); }
	void Serialize(FStructuredArchiveRecord Record) { NativeCall<void, FStructuredArchiveRecord>(this, "UTexture2D.Serialize(FStructuredArchiveRecord)", Record); }
	//void UTexture2D(const FObjectInitializer* ObjectInitializer) { NativeCall<void, const FObjectInitializer*>(this, "UTexture2D.UTexture2D(FObjectInitializer*)", ObjectInitializer); }
	//FTexturePlatformData** GetRunningPlatformData() { return NativeCall<FTexturePlatformData**>(this, "UTexture2D.GetRunningPlatformData()"); }
	int GetNumMips() { return NativeCall<int>(this, "UTexture2D.GetNumMips()"); }
	void Serialize(FArchive* Ar) { NativeCall<void, FArchive*>(this, "UTexture2D.Serialize(FArchive*)", Ar); }
	int GetNumResidentMips() { return NativeCall<int>(this, "UTexture2D.GetNumResidentMips()"); }
	bool IsReadyForAsyncPostLoad() { return NativeCall<bool>(this, "UTexture2D.IsReadyForAsyncPostLoad()"); }
	//void PreSave(FObjectPreSaveContext ObjectSaveContext) { NativeCall<void, FObjectPreSaveContext>(this, "UTexture2D.PreSave(FObjectPreSaveContext)", ObjectSaveContext); }
	//void GetAssetRegistryTags(TArray<UObject::FAssetRegistryTag, TSizedDefaultAllocator<32> >* OutTags) { NativeCall<void, TArray<UObject::FAssetRegistryTag, TSizedDefaultAllocator<32> >*>(this, "UTexture2D.GetAssetRegistryTags(TArray<UObject::FAssetRegistryTag,TSizedDefaultAllocator<32>>*)", OutTags); }
	void UpdateResource() { NativeCall<void>(this, "UTexture2D.UpdateResource()"); }
	void BeginDestroy() { NativeCall<void>(this, "UTexture2D.BeginDestroy()"); }
	FString* GetDesc(FString* result) { return NativeCall<FString*, FString*>(this, "UTexture2D.GetDesc(FString&)", result); }
	int CalcTextureMemorySize(int MipCount) { return NativeCall<int, int>(this, "UTexture2D.CalcTextureMemorySize(int)", MipCount); }
	int GetNumMipsAllowed(bool bIgnoreMinResidency) { return NativeCall<int, bool>(this, "UTexture2D.GetNumMipsAllowed(bool)", bIgnoreMinResidency); }
	//unsigned int CalcTextureMemorySizeEnum(ETextureMipCount Enum) { return NativeCall<unsigned int, ETextureMipCount>(this, "UTexture2D.CalcTextureMemorySizeEnum(ETextureMipCount)", Enum); }
	//FTextureResource* CreateResource() { return NativeCall<FTextureResource*>(this, "UTexture2D.CreateResource()"); }
	//EMaterialValueType GetMaterialType() { return NativeCall<EMaterialValueType>(this, "UTexture2D.GetMaterialType()"); }
	void GetResourceSizeEx(FResourceSizeEx* CumulativeResourceSize) { NativeCall<void, FResourceSizeEx*>(this, "UTexture2D.GetResourceSizeEx(FResourceSizeEx*)", CumulativeResourceSize); }
	//static UTexture2D* CreateTransient(int InSizeX, int InSizeY, EPixelFormat InFormat, const FName InName) { return NativeCall<UTexture2D*, int, int, EPixelFormat, const FName>(nullptr, "UTexture2D.CreateTransient(int,int,EPixelFormat,FName)", InSizeX, InSizeY, InFormat, InName); }
	static float GetGlobalMipMapLODBias() { return NativeCall<float>(nullptr, "UTexture2D.GetGlobalMipMapLODBias()"); }
	void RefreshSamplerStates() { NativeCall<void>(this, "UTexture2D.RefreshSamplerStates()"); }
	bool IsCurrentlyVirtualTextured() { return NativeCall<bool>(this, "UTexture2D.IsCurrentlyVirtualTextured()"); }
	bool StreamIn(int NewMipCount, bool bHighPrio) { return NativeCall<bool, int, bool>(this, "UTexture2D.StreamIn(int,bool)", NewMipCount, bHighPrio); }
	bool StreamOut(int NewMipCount) { return NativeCall<bool, int>(this, "UTexture2D.StreamOut(int)", NewMipCount); }
	void GetMipData(int FirstMipToLoad, void** OutMipData) { NativeCall<void, int, void**>(this, "UTexture2D.GetMipData(int,void**)", FirstMipToLoad, OutMipData); }
};

struct FItemNetInfo
{
	// Fields

	//TSubclassOf<UPrimalItem>& ItemArchetypeField() { return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, "FItemNetInfo.ItemArchetype"); }
	FItemNetID& ItemIDField() { return *GetNativePointerField<FItemNetID*>(this, "FItemNetInfo.ItemID"); }
	unsigned int& ItemQuantityField() { return *GetNativePointerField<unsigned int*>(this, "FItemNetInfo.ItemQuantity"); }
	int& CustomItemIDField() { return *GetNativePointerField<int*>(this, "FItemNetInfo.CustomItemID"); }
	int& SlotIndexField() { return *GetNativePointerField<int*>(this, "FItemNetInfo.SlotIndex"); }
	long double& CreationTimeField() { return *GetNativePointerField<long double*>(this, "FItemNetInfo.CreationTime"); }
	FString& CustomItemNameField() { return *GetNativePointerField<FString*>(this, "FItemNetInfo.CustomItemName"); }
	FString& CustomItemDescriptionField() { return *GetNativePointerField<FString*>(this, "FItemNetInfo.CustomItemDescription"); }
	long double& UploadEarliestValidTimeField() { return *GetNativePointerField<long double*>(this, "FItemNetInfo.UploadEarliestValidTime"); }
	TArray<unsigned __int64, TSizedDefaultAllocator<32> >& SteamUserItemIDField() { return *GetNativePointerField<TArray<unsigned __int64, TSizedDefaultAllocator<32> >*>(this, "FItemNetInfo.SteamUserItemID"); }
	__int16& _padding_62Field() { return *GetNativePointerField<__int16*>(this, "FItemNetInfo._padding_62"); }
	unsigned __int16& CraftQueueField() { return *GetNativePointerField<unsigned __int16*>(this, "FItemNetInfo.CraftQueue"); }
	long double& NextCraftCompletionTimeField() { return *GetNativePointerField<long double*>(this, "FItemNetInfo.NextCraftCompletionTime"); }
	float& CraftingSkillField() { return *GetNativePointerField<float*>(this, "FItemNetInfo.CraftingSkill"); }
	float& CraftedSkillBonusField() { return *GetNativePointerField<float*>(this, "FItemNetInfo.CraftedSkillBonus"); }
	FString& CrafterCharacterNameField() { return *GetNativePointerField<FString*>(this, "FItemNetInfo.CrafterCharacterName"); }
	FString& CrafterTribeNameField() { return *GetNativePointerField<FString*>(this, "FItemNetInfo.CrafterTribeName"); }
	unsigned int& WeaponClipAmmoField() { return *GetNativePointerField<unsigned int*>(this, "FItemNetInfo.WeaponClipAmmo"); }
	float& ItemDurabilityField() { return *GetNativePointerField<float*>(this, "FItemNetInfo.ItemDurability"); }
	float& ItemRatingField() { return *GetNativePointerField<float*>(this, "FItemNetInfo.ItemRating"); }
	unsigned int& ExpirationTimeUTCField() { return *GetNativePointerField<unsigned int*>(this, "FItemNetInfo.ExpirationTimeUTC"); }
	//TSubclassOf<UPrimalItem>& ItemCustomClassField() { return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, "FItemNetInfo.ItemCustomClass"); }
	//unsigned __int16[8] & ItemStatValuesField() { return *GetNativePointerField<unsigned __int16[8] *>(this, "FItemNetInfo.ItemStatValues"); }
	//__int16[6] & ItemColorIDField() { return *GetNativePointerField<__int16[6] *>(this, "FItemNetInfo.ItemColorID"); }
	//TSubclassOf<UPrimalItem>& ItemSkinTemplateField() { return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, "FItemNetInfo.ItemSkinTemplate"); }
	TArray<FCustomItemData, TSizedDefaultAllocator<32> >& CustomItemDatasField() { return *GetNativePointerField<TArray<FCustomItemData, TSizedDefaultAllocator<32> >*>(this, "FItemNetInfo.CustomItemDatas"); }
	TArray<FColor, TSizedDefaultAllocator<32> >& CustomItemColorsField() { return *GetNativePointerField<TArray<FColor, TSizedDefaultAllocator<32> >*>(this, "FItemNetInfo.CustomItemColors"); }
	TArray<FCraftingResourceRequirement, TSizedDefaultAllocator<32> >& CustomResourceRequirementsField() { return *GetNativePointerField<TArray<FCraftingResourceRequirement, TSizedDefaultAllocator<32> >*>(this, "FItemNetInfo.CustomResourceRequirements"); }
	long double& NextSpoilingTimeField() { return *GetNativePointerField<long double*>(this, "FItemNetInfo.NextSpoilingTime"); }
	long double& LastSpoilingTimeField() { return *GetNativePointerField<long double*>(this, "FItemNetInfo.LastSpoilingTime"); }
	unsigned __int64& OwnerPlayerDataIdField() { return *GetNativePointerField<unsigned __int64*>(this, "FItemNetInfo.OwnerPlayerDataId"); }
	//TWeakObjectPtr<AShooterCharacter, FWeakObjectPtr>& LastOwnerPlayerField() { return *GetNativePointerField<TWeakObjectPtr<AShooterCharacter, FWeakObjectPtr>*>(this, "FItemNetInfo.LastOwnerPlayer"); }
	long double& LastAutoDurabilityDecreaseTimeField() { return *GetNativePointerField<long double*>(this, "FItemNetInfo.LastAutoDurabilityDecreaseTime"); }
	float& ItemStatClampsMultiplierField() { return *GetNativePointerField<float*>(this, "FItemNetInfo.ItemStatClampsMultiplier"); }
	UE::Math::TVector<double>& OriginalItemDropLocationField() { return *GetNativePointerField<UE::Math::TVector<double>*>(this, "FItemNetInfo.OriginalItemDropLocation"); }
	//__int16[6] & PreSkinItemColorIDField() { return *GetNativePointerField<__int16[6] *>(this, "FItemNetInfo.PreSkinItemColorID"); }
	//unsigned __int8[12] & EggNumberOfLevelUpPointsAppliedField() { return *GetNativePointerField<unsigned __int8[12] *>(this, "FItemNetInfo.EggNumberOfLevelUpPointsApplied"); }
	//unsigned __int8[12] & EggNumberMutationsAppliedField() { return *GetNativePointerField<unsigned __int8[12] *>(this, "FItemNetInfo.EggNumberMutationsApplied"); }
	float& EggTamedIneffectivenessModifierField() { return *GetNativePointerField<float*>(this, "FItemNetInfo.EggTamedIneffectivenessModifier"); }
	//unsigned __int8[6] & EggColorSetIndicesField() { return *GetNativePointerField<unsigned __int8[6] *>(this, "FItemNetInfo.EggColorSetIndices"); }
	int& EggGenderOverrideField() { return *GetNativePointerField<int*>(this, "FItemNetInfo.EggGenderOverride"); }
	long double& ClusterSpoilingTimeUTCField() { return *GetNativePointerField<long double*>(this, "FItemNetInfo.ClusterSpoilingTimeUTC"); }
	TArray<FDinoAncestorsEntry, TSizedDefaultAllocator<32> >& EggDinoAncestorsField() { return *GetNativePointerField<TArray<FDinoAncestorsEntry, TSizedDefaultAllocator<32> >*>(this, "FItemNetInfo.EggDinoAncestors"); }
	TArray<FDinoAncestorsEntry, TSizedDefaultAllocator<32> >& EggDinoAncestorsMaleField() { return *GetNativePointerField<TArray<FDinoAncestorsEntry, TSizedDefaultAllocator<32> >*>(this, "FItemNetInfo.EggDinoAncestorsMale"); }
	int& EggRandomMutationsFemaleField() { return *GetNativePointerField<int*>(this, "FItemNetInfo.EggRandomMutationsFemale"); }
	int& EggRandomMutationsMaleField() { return *GetNativePointerField<int*>(this, "FItemNetInfo.EggRandomMutationsMale"); }
	bool& bNetInfoFromClientField() { return *GetNativePointerField<bool*>(this, "FItemNetInfo.bNetInfoFromClient"); }

	// Bitfields

	BitFieldValue<bool, unsigned __int32> bIsBlueprint() { return { this, "FItemNetInfo.bIsBlueprint" }; }
	BitFieldValue<bool, unsigned __int32> bIsEngram() { return { this, "FItemNetInfo.bIsEngram" }; }
	BitFieldValue<bool, unsigned __int32> bIsCustomRecipe() { return { this, "FItemNetInfo.bIsCustomRecipe" }; }
	BitFieldValue<bool, unsigned __int32> bIsFoodRecipe() { return { this, "FItemNetInfo.bIsFoodRecipe" }; }
	BitFieldValue<bool, unsigned __int32> bIsRepairing() { return { this, "FItemNetInfo.bIsRepairing" }; }
	BitFieldValue<bool, unsigned __int32> bAllowRemovalFromInventory() { return { this, "FItemNetInfo.bAllowRemovalFromInventory" }; }
	BitFieldValue<bool, unsigned __int32> bHideFromInventoryDisplay() { return { this, "FItemNetInfo.bHideFromInventoryDisplay" }; }
	BitFieldValue<bool, unsigned __int32> bAllowRemovalFromSteamInventory() { return { this, "FItemNetInfo.bAllowRemovalFromSteamInventory" }; }
	BitFieldValue<bool, unsigned __int32> bFromSteamInventory() { return { this, "FItemNetInfo.bFromSteamInventory" }; }
	BitFieldValue<bool, unsigned __int32> bIsFromAllClustersInventory() { return { this, "FItemNetInfo.bIsFromAllClustersInventory" }; }
	BitFieldValue<bool, unsigned __int32> bForcePreventGrinding() { return { this, "FItemNetInfo.bForcePreventGrinding" }; }
	BitFieldValue<bool, unsigned __int32> bIsEquipped() { return { this, "FItemNetInfo.bIsEquipped" }; }
	BitFieldValue<bool, unsigned __int32> bIsSlot() { return { this, "FItemNetInfo.bIsSlot" }; }
	BitFieldValue<bool, unsigned __int32> bIsInitialItem() { return { this, "FItemNetInfo.bIsInitialItem" }; }

	// Functions

	//void FItemNetInfo(const FItemNetInfo* __that) { NativeCall<void, const FItemNetInfo*>(this, "FItemNetInfo.FItemNetInfo(FItemNetInfo*)", __that); }
	//void ~FItemNetInfo() { NativeCall<void>(this, "FItemNetInfo.~FItemNetInfo()"); }
	//void FItemNetInfo() { NativeCall<void>(this, "FItemNetInfo.FItemNetInfo()"); }
	static UScriptStruct* StaticStruct() { return NativeCall<UScriptStruct*>(nullptr, "FItemNetInfo.StaticStruct()"); }
	FItemNetInfo* operator=(FItemNetInfo* __that) { return NativeCall<FItemNetInfo*, FItemNetInfo*>(this, "FItemNetInfo.operator=(FItemNetInfo*)", __that); }
	FItemNetInfo* operator=(const FItemNetInfo* __that) { return NativeCall<FItemNetInfo*, const FItemNetInfo*>(this, "FItemNetInfo.operator=(FItemNetInfo*)", __that); }
	//void FItemNetInfo(FItemNetInfo* __that) { NativeCall<void, FItemNetInfo*>(this, "FItemNetInfo.FItemNetInfo(FItemNetInfo*)", __that); }
	bool NetSerialize(FArchive* Ar, UPackageMap* Map, bool* bOutSuccess) { return NativeCall<bool, FArchive*, UPackageMap*, bool*>(this, "FItemNetInfo.NetSerialize(FArchive*,UPackageMap*,bool*)", Ar, Map, bOutSuccess); }
};
