//CONSTS
const $accordionItemsTop = $('.m_accordion__item-top');
const transitionTime = 500;


//EVENTS
$accordionItemsTop.click(function(){
    handleItemClick($(this))
});

//FUNCTIONS
function handleItemClick($clickedItemTop){
    const $clickedItemBottom = $clickedItemTop.next('.m_accordion__item-bottom');
    const $clickedItemTopParent = $clickedItemTop.parent();
    const isClickedItemActive = $clickedItemTopParent.hasClass('m_accordion__item--active');

    if(isClickedItemActive) {
        $clickedItemBottom.slideUp(transitionTime);
        $clickedItemTopParent.removeClass('m_accordion__item--active');
    }
    else if (!isClickedItemActive) {
        const $activeItem = $('.m_accordion__item--active');
        $activeItem.children('.m_accordion__item-bottom').slideUp(transitionTime);
        $activeItem.removeClass('m_accordion__item--active');
        $clickedItemBottom.slideDown(transitionTime);
        $clickedItemTopParent.addClass('m_accordion__item--active')
    }
    else {
        $clickedItemBottom.slideDown(transitionTime);
        $clickedItemTopParent.addClass('m_accordion__item--active')
    }
}