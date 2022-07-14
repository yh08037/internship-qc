import os, sys, glob


project_name = 'internship-qc'
exec_name = 'mapping'

project_dir = os.getcwd().split(project_name)[0] + project_name

exec_path = project_dir + f'/build/{exec_name}'
circuit_dir = project_dir + '/circuits/'

circuits = sorted(glob.glob(circuit_dir + '*.qasm'))


if __name__ == '__main__':

    if len(sys.argv) != 2:
        print(f'usage: python3 run.py [0~{len(circuits)-1}]')
        print(f'       python3 run.py list')
        sys.exit()

    num_str = sys.argv[1]

    if num_str == 'list':
        print('available benchmarks')
        for i, circuit in enumerate(circuits):
            print(f'  {i}: {os.path.basename(circuit)}')

    elif num_str.isdigit():
        num = int(num_str)
        os.system(f'{exec_path} {circuits[num]}')

    else:
        print(f'usage: python3 run.py [0~{len(circuits)-1}]')
        print(f'       python3 run.py list')
        sys.exit()
