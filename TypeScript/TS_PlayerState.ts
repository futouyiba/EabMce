import * as UE from 'ue'
import {$ref, $unref} from 'puerts'

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
    // 准备在加入、去除的时候，都用 数组+字典 的形式，一边记录每个元素是什么，一边记录对应一种加成物品捡到了几个
    /* 其实这是在考虑一个问题：我们对于加成物品的显示到底是平铺显示还是叠起来（对于相同的加物）显示个数？
    在思考的方面包括：
    先得到后得到肯定得显示的时候有顺序吧。
    用map的缺点在于其先后顺序问题，它会根据hash来排序，这不是我们想要的。所以这个map应该到后来不会用。
    那么如果用struct，struct可以套层也可以不套。
    套层：
    ps持有一个itemWithCount的结构体的数组?

    其实直接使用一个arr和一个map就可以了。这样对于数量的存取比较快速，不用每次都去find（若用一个套层struct就需要find）。虽然对于一个n比较小的数组，find并不太耗时间。
     */
    RogueItemNumMap: UE.TMap<string, number>;
    RogueItemsArr : UE.TArray<string>;

    // ItemCounts: UE.TArray<RogueItemWithCount>;

    // RogueMapPlus(itemName:string):void{

    // }

    AddRogueItem(itemName:string):void{
        let itemNum = this.RogueItemNumMap.Get(itemName); // 在d ts文件里没找到trygetvalue，那么很可能用get达到相同的效果
        if (itemNum==undefined) {
            console.error("the item num map is not correctly inited... should be set when player state is constructed...", this.PlayerId);
            return;
            // this.RogueItemNumMap.Set(itemName, 1);
        }else {
            if(itemNum==0){ // 当原为0的时候，要额外把这个item name加到列表的新栏目。这样界面的显示顺序更合理
                this.RogueItemsArr.Add(itemName);
            }
            this.RogueItemNumMap.Set(itemName, itemNum+1);
        }
    }

    RemoveRogueItem(itemName:string):void{
        let itemNum = this.RogueItemNumMap.Get(itemName); // 在d ts文件里没找到trygetvalue，那么很可能用get达到相同的效果
        if (itemNum==undefined) {
            console.error("the item num map is not correctly inited, or incorrect itemName... should be set when player state is constructed...", this.PlayerId);
            return;
            // this.RogueItemNumMap.Set(itemName, 1);
        }else {//TODO add check for itemNum <= 0
            if(itemNum<=1){ // 当原为0的时候，要额外把这个item name加到列表的新栏目。这样界面的显示顺序更合理
                let index = this.RogueItemsArr.FindIndex(itemName);
                if (index == -1) {
                    console.error("trying to remove item that I don't have now... my playerId is...", this.PlayerId);
                }

            }
            this.RogueItemNumMap.Set(itemName, itemNum-1);
        }
    }


    // 这里我们做一个字典的初始化。
    ReceiveBeginPlay(): void {
        super.ReceiveBeginPlay();
        console.info("before rowName print, my playerId is:", this.PlayerId, this.GetName(), this.GetPlayerName());

        let rowNamesOut = $ref<UE.TArray<string>>(undefined);
        // 从datatable的rowName跑个循环
        // TODO write extension for array, and write extension for data tables...
        UE.DataTableFunctionLibrary.GetDataTableRowNames(this.DT_RogueItems, rowNamesOut);
        let rowNames = $unref(rowNamesOut);
        let count = rowNames.Num();
        for (let i = 0; i < count; i++) {
            const rowName = rowNames.Get(i);
            this.RogueItemNumMap.Add(rowName, 0);
            console.warn("rowName is:", rowName);
        }
    }
}

export default TS_PlayerState;
