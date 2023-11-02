#pragma once
//#include "Actor.h"
struct UObject;
struct FWeakObjectPtr
{
	int ObjectIndex;
	int ObjectSerialNumber;

	void operator=(UObject const* __that) { return NativeCall<void, UObject const*>(this, "FWeakObjectPtr.operator=", __that); }
	UObject* Get(bool bEvenIfPendingKill = false) { return NativeCall<UObject*, bool>(this, "FWeakObjectPtr.Get", bEvenIfPendingKill); }
	//	bool IsValid() { return NativeCall<bool>(this, "FWeakObjectPtr.IsValid"); }
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
		return NativeCall<T*, bool>(this, "FWeakObjectPtr.Get", bEvenIfPendingKill);
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
	UClass* ClassField() { return *GetNativePointerField<UClass**>(this, "UObjectBase.ClassPrivate"); }
};

struct UObjectBaseUtility : UObjectBase
{
};

struct UObject : UObjectBaseUtility
{
	// Fields


	  // Bitfields


	  // Functions

	bool ProcessConsoleExec(const wchar_t* Cmd, FOutputDevice* Ar, UObject* Executor) { return NativeCall<bool>(this, "UObject.ProcessConsoleExec(wchar_t*,FOutputDevice*,UObject*)", Cmd, Ar, Executor); }
	FString* GetDetailedInfoInternal(FString* result) { return NativeCall<FString*>(this, "UObject.GetDetailedInfoInternal(FString*)", result); }
	~UObject() { NativeCall<void>(this, "UObject.~UObject()"); }
	static UClass* StaticClass() { return NativeCall<UClass*>(nullptr, "UObject.StaticClass()"); }
	// unsigned __int64 GetResourceSizeBytes(EResourceSizeMode::Type Mode) { return NativeCall<unsigned __int64>(this, "UObject.GetResourceSizeBytes(EResourceSizeMode::Type)", Mode); }
	bool AreAllOuterObjectsValid() { return NativeCall<bool>(this, "UObject.AreAllOuterObjectsValid()"); }
	bool IsInBlueprint() { return NativeCall<bool>(this, "UObject.IsInBlueprint()"); }
	bool IsBasedOnArchetype(const UObject* const SomeObject) { return NativeCall<bool>(this, "UObject.IsBasedOnArchetype(UObject*const)", SomeObject); }
	// UObject* CreateDefaultSubobject(FName SubobjectFName, UClass* ReturnType, UClass* ClassToCreateByDefault, bool bIsRequired, bool bIsTransient) { return NativeCall<UObject*>(this, "UObject.CreateDefaultSubobject(FName,UClass*,UClass*,bool,bool)", SubobjectFName, ReturnType, ClassToCreateByDefault, bIsRequired, bIsTransient); }
	 //UObject* GetDefaultSubobjectByName(FName ToFind) { return NativeCall<UObject*>(this, "UObject.GetDefaultSubobjectByName(FName)", ToFind); }
	bool Rename(const wchar_t* InName, UObject* NewOuter, unsigned int Flags) { return NativeCall<bool>(this, "UObject.Rename(wchar_t*,UObject*,unsignedint)", InName, NewOuter, Flags); }
	void PostLoad() { NativeCall<void>(this, "UObject.PostLoad()"); }
	bool NeedsLoadForServer() { return NativeCall<bool>(this, "UObject.NeedsLoadForServer()"); }
	bool NeedsLoadForClient() { return NativeCall<bool>(this, "UObject.NeedsLoadForClient()"); }
	void BeginDestroy() { NativeCall<void>(this, "UObject.BeginDestroy()"); }
	void FinishDestroy() { NativeCall<void>(this, "UObject.FinishDestroy()"); }
	FString* GetDetailedInfo(FString* result) { return NativeCall<FString*>(this, "UObject.GetDetailedInfo(FString*)", result); }
	bool ConditionalBeginDestroy() { return NativeCall<bool>(this, "UObject.ConditionalBeginDestroy()"); }
	bool ConditionalFinishDestroy() { return NativeCall<bool>(this, "UObject.ConditionalFinishDestroy()"); }
	void ConditionalPostLoad() { NativeCall<void>(this, "UObject.ConditionalPostLoad()"); }
	// void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) { NativeCall<void>(this, "UObject.PostLoadSubobjects(FObjectInstancingGraph*)", OuterInstanceGraph); }
	// void ConditionalPostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) { NativeCall<void>(this, "UObject.ConditionalPostLoadSubobjects(FObjectInstancingGraph*)", OuterInstanceGraph); }
	// void PreSave(FObjectPreSaveContext SaveContext) { NativeCall<void>(this, "UObject.PreSave(FObjectPreSaveContext)", SaveContext); }
	void GetPreloadDependencies(TArray<UObject*, TSizedDefaultAllocator<32> >* OutDeps) { NativeCall<void>(this, "UObject.GetPreloadDependencies(TArray<UObject*,TSizedDefaultAllocator<32>>*)", OutDeps); }
	void Serialize(FStructuredArchiveRecord Record) { NativeCall<void>(this, "UObject.Serialize(FStructuredArchiveRecord)", Record); }
	void SerializeScriptProperties(FArchive* Ar) { NativeCall<void>(this, "UObject.SerializeScriptProperties(FArchive*)", Ar); }
	void SerializeScriptProperties(FStructuredArchiveSlot Slot) { NativeCall<void>(this, "UObject.SerializeScriptProperties(FStructuredArchiveSlot)", Slot); }
	void BuildSubobjectMapping(UObject* OtherObject, TMap<UObject*, UObject*, FDefaultSetAllocator, TDefaultMapHashableKeyFuncs<UObject*, UObject*, 0> >* ObjectMapping) { NativeCall<void>(this, "UObject.BuildSubobjectMapping(UObject*,TMap<UObject*,UObject*,FDefaultSetAllocator,TDefaultMapHashableKeyFuncs<UObject*,UObject*,0>>*)", OtherObject, ObjectMapping); }
	void CollectDefaultSubobjects(TArray<UObject*, TSizedDefaultAllocator<32> >* OutSubobjectArray, bool bIncludeNestedSubobjects) { NativeCall<void>(this, "UObject.CollectDefaultSubobjects(TArray<UObject*,TSizedDefaultAllocator<32>>*,bool)", OutSubobjectArray, bIncludeNestedSubobjects); }
	bool CheckDefaultSubobjects(bool bForceCheck) { return NativeCall<bool>(this, "UObject.CheckDefaultSubobjects(bool)", bForceCheck); }
	bool CheckDefaultSubobjectsInternal() { return NativeCall<bool>(this, "UObject.CheckDefaultSubobjectsInternal()"); }
	//  void GetAssetRegistryTags(TArray<UObject::FAssetRegistryTag, TSizedDefaultAllocator<32> >* OutTags) { NativeCall<void>(this, "UObject.GetAssetRegistryTags(TArray<UObject::FAssetRegistryTag,TSizedDefaultAllocator<32>>*)", OutTags); }
	//  void GetAssetRegistryTags(FAssetData* Out) { NativeCall<void>(this, "UObject.GetAssetRegistryTags(FAssetData*)", Out); }
	static const FName* AssetVersePathTagName() { return NativeCall<const FName*>(nullptr, "UObject.AssetVersePathTagName()"); }
	void GetResourceSizeEx(FResourceSizeEx* CumulativeResourceSize) { NativeCall<void>(this, "UObject.GetResourceSizeEx(FResourceSizeEx*)", CumulativeResourceSize); }
	bool IsAsset() { return NativeCall<bool>(this, "UObject.IsAsset()"); }
	//   FPrimaryAssetId* GetPrimaryAssetId(FPrimaryAssetId* result) { return NativeCall<FPrimaryAssetId*>(this, "UObject.GetPrimaryAssetId(FPrimaryAssetId*)", result); }
	bool IsLocalizedResource() { return NativeCall<bool>(this, "UObject.IsLocalizedResource()"); }
	bool IsSafeForRootSet() { return NativeCall<bool>(this, "UObject.IsSafeForRootSet()"); }
	// void TagSubobjects(EObjectFlags NewFlags) { NativeCall<void>(this, "UObject.TagSubobjects(EObjectFlags)", NewFlags); }
	void LoadConfig(UClass* ConfigClass, const wchar_t* InFilename, unsigned int PropagationFlags, FProperty* PropertyToLoad) { NativeCall<void>(this, "UObject.LoadConfig(UClass*,wchar_t*,unsignedint,FProperty*)", ConfigClass, InFilename, PropagationFlags, PropertyToLoad); }
	//  void SaveConfig(unsigned __int64 Flags, const wchar_t* InFilename, FConfigCacheIni* Config, bool bAllowCopyToDefaultObject) { NativeCall<void>(this, "UObject.SaveConfig(unsigned__int64,wchar_t*,FConfigCacheIni*,bool)", Flags, InFilename, Config, bAllowCopyToDefaultObject); }
	FString* GetDefaultConfigFilename(FString* result) { return NativeCall<FString*>(this, "UObject.GetDefaultConfigFilename(FString*)", result); }
	bool IsNameStableForNetworking() { return NativeCall<bool>(this, "UObject.IsNameStableForNetworking()"); }
	bool IsFullNameStableForNetworking() { return NativeCall<bool>(this, "UObject.IsFullNameStableForNetworking()"); }
	bool IsSupportedForNetworking() { return NativeCall<bool>(this, "UObject.IsSupportedForNetworking()"); }
	void LocalizeProperty(UObject* LocBase, TArray<FString, TSizedDefaultAllocator<32> >* PropertyTagChain, FProperty* const BaseProperty, FProperty* const Property, void* const ValueAddress) { NativeCall<void>(this, "UObject.LocalizeProperty(UObject*,TArray<FString,TSizedDefaultAllocator<32>>*,FProperty*const,FProperty*const,void*const)", LocBase, PropertyTagChain, BaseProperty, Property, ValueAddress); }
	// void SkipFunction(FFrame* Stack, void* const Z_Param__Result, UFunction* Function) { NativeCall<void>(this, "UObject.SkipFunction(FFrame*,void*const,UFunction*)", Stack, Z_Param__Result, Function); }
	// void CallFunction(FFrame* Stack, void* const Z_Param__Result, UFunction* Function) { NativeCall<void>(this, "UObject.CallFunction(FFrame*,void*const,UFunction*)", Stack, Z_Param__Result, Function); }
  //   static void ProcessInternal(UObject* Context, FFrame* Stack, void* const Z_Param__Result) { NativeCall<void>(nullptr, "UObject.ProcessInternal(UObject*,FFrame*,void*const)", Context, Stack, Z_Param__Result); }
	bool CallFunctionByNameWithArguments(const wchar_t* Str, FOutputDevice* Ar, UObject* Executor, bool bForceCallWithNonExec) { return NativeCall<bool>(this, "UObject.CallFunctionByNameWithArguments(wchar_t*,FOutputDevice*,UObject*,bool)", Str, Ar, Executor, bForceCallWithNonExec); }
	//    UFunction* FindFunctionChecked(FName InName) { return NativeCall<UFunction*>(this, "UObject.FindFunctionChecked(FName)", InName); }
	void ProcessEvent(UFunction* Function, void* Parms) { NativeCall<void>(this, "UObject.ProcessEvent(UFunction*,void*)", Function, Parms); }
	//   void ProcessContextOpcode(FFrame* Stack, void* const Z_Param__Result, bool bCanFailSilently) { NativeCall<void>(this, "UObject.ProcessContextOpcode(FFrame*,void*const,bool)", Stack, Z_Param__Result, bCanFailSilently); }
	 //  void execIntZero(FBehaviorTreeSearchData* SearchData, EBTNodeResult::Type* NodeResult) { NativeCall<void>(this, "UObject.execIntZero(FBehaviorTreeSearchData*,EBTNodeResult::Type*)", SearchData, NodeResult); }
	UObject* GetArchetype() { return NativeCall<UObject*>(this, "UObject.GetArchetype()"); }
	bool IsInOrOwnedBy(const UObject* SomeOuter) { return NativeCall<bool>(this, "UObject.IsInOrOwnedBy(UObject*)", SomeOuter); }
	UObject() { NativeCall<void>(this, "UObject.UObject()"); }
	void SetLinker(FLinkerLoad* LinkerLoad, int LinkerIndex, bool bShouldDetachExisting) { NativeCall<void>(this, "UObject.SetLinker(FLinkerLoad*,int,bool)", LinkerLoad, LinkerIndex, bShouldDetachExisting); }
};


struct UTexture : UObject
{
	static UClass* StaticClass() { return NativeCall<UClass*>(nullptr, "UTexture.StaticClass"); }
};

struct UTexture2D : UTexture
{
};