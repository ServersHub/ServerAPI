#pragma once
struct AActor;
struct UObject;
struct UPrimalItem : UObject {
	//functions:
	FString* GetItemName(FString* result, bool bIncludeQuantity, bool bShortName, AShooterPlayerController* ForPC) { return NativeCall<FString*, FString*, bool, bool, AShooterPlayerController*>(this, "UPrimalItem.GetItemName", result, bIncludeQuantity, bShortName, ForPC); }
	int GetItemQuantity() { return NativeCall<int>(this, "UPrimalItem.GetItemQuantity"); }
};
struct ADroppedItem : AActor {

};
struct UActorComponent : UObject
{

};
struct UPrimalInventoryComponent : UActorComponent
{
	TArray<UPrimalItem*, TSizedDefaultAllocator<32>> InventoryItemsField() { return *GetNativePointerField<TArray<UPrimalItem*, TSizedDefaultAllocator<32>>*>(this, "UPrimalInventoryComponent.InventoryItems"); }
	TArray<UPrimalItem*, TSizedDefaultAllocator<32>> EquippedItemsField() { return *GetNativePointerField<TArray<UPrimalItem*, TSizedDefaultAllocator<32>>*>(this, "UPrimalInventoryComponent.EquippedItems"); }
	TArray<UPrimalItem*, TSizedDefaultAllocator<32>> ItemSlotsField() { return *GetNativePointerField<TArray<UPrimalItem*, TSizedDefaultAllocator<32>>*>(this, "UPrimalInventoryComponent.ItemSlots"); }
	TArray<UPrimalItem*, TSizedDefaultAllocator<32>> ArkTributeItemsField() { return *GetNativePointerField<TArray<UPrimalItem*, TSizedDefaultAllocator<32>>*>(this, "UPrimalInventoryComponent.ArkTributeItems"); }
	TArray<UPrimalItem*, TSizedDefaultAllocator<32>> AllDyeColorItemsField() { return *GetNativePointerField<TArray<UPrimalItem*, TSizedDefaultAllocator<32>>*>(this, "UPrimalInventoryComponent.AllDyeColorItems"); }
};