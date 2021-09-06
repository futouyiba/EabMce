import * as UE from 'ue'
import {$ref, $unref} from 'puerts'

class TS_BonusItemWidget extends UE.UserWidget{
    // add functions for state machine to use
    SetTextureFromName(itemName:string):void{}
    SetStackNum(stacks:number):void{}
}

export default TS_BonusItemWidget;