$fileVersion = 1,8,5,0
$productVersion = 1,8,5,0

if ($Env:GITHUB_ACTIONS -eq "true") {
    $fileVersion[3] = [int]$Env:GITHUB_RUN_NUMBER
    $productVersion[3] = [int]$Env:GITHUB_RUN_NUMBER
}
