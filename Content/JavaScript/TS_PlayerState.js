"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const UE = require("ue");
const puerts_1 = require("puerts");
console.warn("Script init of RoguePlayerState ");
// class RogueItemWithCount {
//     // 这是一个唯一标识，用来查找datatable，实际上就是datatable的rowName。
//     ItemName:string;
//     ItemCount:number;
//     constructor(name:string, count:number){
//         this.ItemName = name;
//         this.ItemCount = count;
//     }
// }
class TS_PlayerState extends UE.EAB_DefaultPlayerState {
    // ItemCounts: UE.TArray<RogueItemWithCount>;
    // RogueMapPlus(itemName:string):void{
    // }
    AddRogueItem(itemName) {
        let itemNum = this.RogueItemNumMap.Get(itemName); // 在d ts文件里没找到trygetvalue，那么很可能用get达到相同的效果
        if (itemNum == undefined) {
            console.error("the item num map is not correctly inited... should be set when player state is constructed...", this.PlayerId);
            return;
            // this.RogueItemNumMap.Set(itemName, 1);
        }
        else {
            if (itemNum == 0) { // 当原为0的时候，要额外把这个item name加到列表的新栏目。这样界面的显示顺序更合理
                this.RogueItemsArr.Add(itemName);
            }
            this.RogueItemNumMap.Set(itemName, itemNum + 1);
        }
    }
    RemoveRogueItem(itemName) {
        let itemNum = this.RogueItemNumMap.Get(itemName); // 在d ts文件里没找到trygetvalue，那么很可能用get达到相同的效果
        if (itemNum == undefined) {
            console.error("the item num map is not correctly inited, or incorrect itemName... should be set when player state is constructed...", this.PlayerId);
            return;
            // this.RogueItemNumMap.Set(itemName, 1);
        }
        else { //TODO add check for itemNum <= 0
            if (itemNum <= 1) { // 当原为0的时候，要额外把这个item name加到列表的新栏目。这样界面的显示顺序更合理
                let index = this.RogueItemsArr.FindIndex(itemName);
                if (index == -1) {
                    console.error("trying to remove item that I don't have now... my playerId is...", this.PlayerId);
                }
            }
            this.RogueItemNumMap.Set(itemName, itemNum - 1);
        }
    }
    // 这里我们做一个字典的初始化。
    ReceiveBeginPlay() {
        super.ReceiveBeginPlay();
        console.info("before rowName print, my playerId is:", this.PlayerId, this.GetName(), this.GetPlayerName());
        let rowNamesOut = puerts_1.$ref(undefined);
        // 从datatable的rowName跑个循环
        // TODO write extension for array, and write extension for data tables...
        UE.DataTableFunctionLibrary.GetDataTableRowNames(this.DT_RogueItems, rowNamesOut);
        let rowNames = puerts_1.$unref(rowNamesOut);
        let count = rowNames.Num();
        for (let i = 0; i < count; i++) {
            const rowName = rowNames.Get(i);
            this.RogueItemNumMap.Add(rowName, 0);
            console.warn("rowName is:", rowName);
        }
    }
}
exports.default = TS_PlayerState;
//# sourceMappingURL=TS_PlayerState.js.map