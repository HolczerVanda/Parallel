using System.Diagnostics;

class Program
{
    static void Main(string[] args)
    {
        if (args.Length != 3)
        {
            Console.WriteLine("Error!");
            return;
        }

        int N = int.Parse(args[0]);
        int maxRecDepth = int.Parse(args[1]);
        int generated = int.Parse(args[2]);

        float[] array = new float[N];
        Random rand = new Random();

        if (generated == 1)
        {
            try
            {
                string filename = "D:\\Egyetem\\Parallel\\beadandok\\randomNumbers.txt";
                StreamReader file = new StreamReader(filename);

                int i = 0;
                float number;
                string line;
                while ((line = file.ReadLine()) != null)
                {
                    if (float.TryParse(line, out number))
                    {
                        array[i] = number;
                        i++;
                    }
                }

                file.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("Error: " + e.Message);
                return;
            }
        }

        else
        {
            for (int i = 0; i < N; i++)
            {
                array[i] = (float)rand.NextDouble();
            }
        }

        Stopwatch stopwatch = Stopwatch.StartNew();

        ParallelMergeSort(array, 0, N - 1, 0, maxRecDepth);

        stopwatch.Stop();
        double timeSpent = (double)stopwatch.ElapsedMilliseconds / 1000.0;

        Console.WriteLine("Elapsed time: {0}", timeSpent);

        string filePath = "output.txt";
        
        try
        {
            using (StreamWriter writer = new StreamWriter(filePath, true))
            {
                writer.WriteLine("{0}", timeSpent);
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }
    }

    static void Merge(float[] array, int left, int middle, int right)
    {
        int i, j, k;
        int leftSize = middle - left + 1;
        int rightSize = right - middle;
        float[] tempLeft = new float[leftSize];
        float[] tempRight = new float[rightSize];

        for (i = 0; i < leftSize; i++)
            tempLeft[i] = array[left + i];

        for (j = 0; j < rightSize; j++)
            tempRight[j] = array[middle + 1 + j];

        i = 0;
        j = 0;
        k = left;

        while (i < leftSize && j < rightSize)
        {
            if (tempLeft[i] <= tempRight[j])
            {
                array[k] = tempLeft[i];
                i++;
            }
            else
            {
                array[k] = tempRight[j];
                j++;
            }
            k++;
        }

        while (i < leftSize)
        {
            array[k] = tempLeft[i];
            i++;
            k++;
        }

        while (j < rightSize)
        {
            array[k] = tempRight[j];
            j++;
            k++;
        }
    }

    static void ParallelMergeSort(float[] array, int left, int right, int recursionDepth, int maxRecDepth)
    {
        if (recursionDepth == maxRecDepth || left >= right)
            return;

        int middle = left + (right - left) / 2;

        Parallel.Invoke(
            () => ParallelMergeSort(array, left, middle, recursionDepth + 1, maxRecDepth),
            () => ParallelMergeSort(array, middle + 1, right, recursionDepth + 1, maxRecDepth)
        );

        Merge(array, left, middle, right);
    }
}
