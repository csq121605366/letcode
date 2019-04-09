class Sort {
  constructor() {

  }
  /**
   * 直接插入算法
   * 基本思想：在要排序的一组数中，假设前面(n-1) [n>=2] 个数已经是排
   * 好顺序的，现在要把第n个数插到前面的有序数中，使得这n个数
   * 也是排好顺序的。如此反复循环，直到全部排好顺序。
   */
  insertSort(array) {
    let i, j, tmp;
    for (i = 0; i < array.length; i++) {
      tmp = array[i];
      for (j = i; j > 0 && tmp < array[j - 1]; j--) {
        array[j] = array[j - 1];
      }
      array[j] = tmp;
    }
    return array;
  }

  /**
   * 希尔排序
   * 基本思想：按照某一增量d分成若干组，每组下标相差d。对每组中全部元素进行直接插入排序。
   * 然后再用一个较小的增量(d/2)对它进行分组，在每组中再进行直接插入排序。当增量变为1时，
   * 进行直接插入排序后，排序完成。
   */
  shellSort(array) {
    let tmp, d = array.length,
      x, i, j;
    while (true) {
      //取增量d
      d = Math.ceil(d / 2);
      //循环d次
      for (x = 0; x < d; x++) {
        //x为(0)到(d-1) 内层比较为 (x+0)和(x+d)和(x+2d).....内层遍历为直接插入排序
        for (i = x + d; i < array.length; i += d) {
          tmp = array[i];
          for (j = i; j >= 0 && tmp < array[j - d]; j -= d) {
            array[j] = array[j - d];
          }
          array[j] = tmp;
        }
      }
      if (d === 1) break;
    }
    return array;
  }

  /**
   * 简单选择排序
   * 基本思想：序列中选出最小的一个数与第一个位置的数进行交换，
   * 然后在剩下的数中再找出最小的与第二个位置的数进行交换。
   */
  selectSort(array) {
    //min标识最小值的位置
    let i, j;
    for (i = 0; i < array.length; i++) {
      for (j = i + 1; j < array.length; j++) {
        //这里可以直接使用解构
        if (array[j] < array[i])[array[j], array[i]] = [array[i], array[j]];
      }
    }
    return array;
  }

  /**
   * 堆排序（最好最坏平均时间复杂度都为O(nlogn)不稳定排序）
   * 基本思想：将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。将其与末尾元素进行交换，
   * 此时末尾就为最大值。然后将剩余n-1个元素重新构造成一个堆，这样会得到n个元素的次小值。
   * 如此反复执行，便能得到一个有序序列了。
   * 步骤一 构造初始堆。将给定无序序列构造成一个大顶堆（一般升序采用大顶堆，降序采用小顶堆)。
   * 步骤二 将堆顶元素与末尾元素进行交换，使末尾元素最大。然后继续调整堆，再将堆顶元素与末尾元素交换，得到第二大元素。如此反复进行交换、重建、交换。
   */
  heapSort(array) {
    //初始化大顶堆
    let middle = Math.ceil(Math.sqrt(array.length));
    for (let i = middle; i >= 0; i--) {
      this.adjustHeap(array, i, array.length);
    }
    //交换堆顶元素和最后节点元素 然后继续调整堆 
    for (let i = array.length - 1; i > 0;) {
      [array[i], array[0]] = [array[0], array[i]];
      i--;
      this.adjustHeap(array, 0, i);
    }
    return array;
  }
  //调整堆
  adjustHeap(array, i, length) {
    let max = i; //最大值索引默认等于父节点
    let k = i * 2 + 1;
    if (k <= length) {
      if (array[max] < array[k]) max = k;
      if (k + 1 <= length && array[max] < array[k + 1]) max = k + 1;
    }
    if (max !== i) {
      [array[max], array[i]] = [array[i], array[max]];
      if (max * 2 <= length) {
        this.adjustHeap(array, max, length)
      }
    }
  }
}

let array = [2, 5, 9, 7, 3, 6, 8, 1, 4];
let sort = new Sort();
console.log(sort.heapSort(array))