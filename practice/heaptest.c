
	private static void heapify(int[] numbers, int length) {
		int i = 0;

		while(i < length){
			int node = numbers[i];
			int lChildIndex = i * 2 + 1;
			int rChildIndex = i * 2 + 2;

			Integer lChild =  ? numbers[lChildIndex] : null;
			Integer rChild =  ? numbers[rChildIndex] : null;

			int smallestChild;

			if(lChildIndex < length && rChildIndex < length) {
				smallestChild = lChild >= rChild ? rChildIndex : lChildIndex;
			} else if (lChildIndex < length) {
				smallestChild = lChildIndex;
			} else if (rChildIndex < length) {
				smallestChild = rChildIndex;
			} else {
				break;
			}

			// We are creating a min heap
			if (node > numbers[smallestChild]) {
				numbers[i] = numbers[smallestChild];
				numbers[smallestChild] = node;
				i = smallestChild;
				continue;
			}

			break;
		}
	}

	public static void sort(int[] numbers) {
		// Build the heap
		for(int i = 0; i < numbers.length; i++) {
			numbers[i] = numbers[i];
			int leaf = i;
			while (leaf > 0) {
				int parent = (leaf - 1) / 2;
				if (numbers[leaf] > numbers[parent]) {
					int temp = numbers[parent];
					numbers[parent] = numbers[leaf];
					numbers[leaf] = temp;
				}
				leaf = parent;
			}
		}

		for(int i = numbers.length - 1; i >= 0; i--) {
			// swap root with last leaf
			int root = numbers[0];
			numbers[0] = numbers[i];
			numbers[i] = root;

			// Only heapify the rest
			heapify(numbers, i);
		}
	}

    /**
     * Main entry: test the HeapSort
     * @param args      {@code String[]} Command line arguments
     */
    public static void main(String[] args) {
        int[] numbers = new int[10];

        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = (int) (Math.random() * 200);
            System.out.print(numbers[i] + " ");
        }
        System.out.println();

        sort(numbers);

        for (int n: numbers)
            System.out.print(n + " ");

        SimpleWriter out = new SimpleWriter1L();
        out.println();
        out.close();
    }
}
